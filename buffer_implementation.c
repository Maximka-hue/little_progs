#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
//Задаем структуру (узел списка)
typedef struct Node {
    char string[5];
    struct Node *next;
} Node;

Node* getNth(Node* , int);
void push(Node **, char * );
Node* getLast(Node *);
void pushBack(Node *, char *);
void insert(Node *, unsigned , char *,int );
int getAll (Node* );
int getLen(Node *);
void deleteList(Node **);
void printLinkedList(const Node *);

//Получить указатель на N-ю структуру
Node* getNth(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}


void push(Node **head, char * input)  //Функция добавления подстроки в конец списка. Зависит от трех параметров:уазатель на последний элемент, указатель на массив с частью исходной строки, дина такой подстроки
	 {
		int j;
		Node * tmp = (Node*) malloc(sizeof(Node));
		for (j=0;j<5;j++)
        {
         tmp->string[j] = '\0';
        }
		for(j=0;j<5;j++)
	    	{
	    	 if(input[j]=='\n'){break;}
	    	 tmp->string[j] = input[j];
	    	}
	    tmp->next = (*head);
	    (*head) = tmp;
}
//Получить указатель на последний элемент спикска
Node* getLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

void pushBack(Node *head, char * input) {
	int j;
    Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    for (j=0;j<5;j++)
    {
     tmp->string[j] = '\0';
    }
    for(j=0;j<5;j++)
    {
    if( input[j]=='\0') {break;}
    tmp->string[j] = input[j];}
    tmp->next = NULL;
    last->next = tmp;
}

/*void insert(Node *head, unsigned n, char * input,int Len) //Функция добавления подстроки в заданную позицию в списке.
	{
	    unsigned i = 0;
	    int j;
		Node * tmp = (Node*) malloc(sizeof(Node));
		while (i < n-1 && head->next)
	    	 {
		         head = head->next;
		         i++;
	     	}
	     for (j=0;j<5;j++)
	     	{
			     tmp->string[j] = input[j];
			  }
		 if (head->next)
			 {
			 	tmp->next = head->next;
	   	   }
	     else
	     	{
	     		tmp->next = NULL;
	     	}
	     head->next = tmp;
}
*/


//Получить количество элементов в списке
int getAll (Node* head) {
	int n=1;
	while (head->next != NULL)
	{
	 head = head->next;
	 n++;
	}
	return n;
}
//Получить длину строки
int getLen(Node *head) {
	int k,s,j;
	Node *tmp=NULL;
	k=getAll(head);
	tmp=getLast(head);
	k--;
	s=k*5;
	for(j=0;j<5;j++)
	{
	 if(tmp->string[j]!='\0')
	 {
	  s++;
	 }
	 return s;
	}
}
//Удалить список
void deleteList(Node **head) {
    Node* prev=NULL;
    if((*head)==NULL){return;}
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
    (*head) = NULL;
}
//Вывести список на экран
void printLinkedList(const Node *head) {
	int s=1;

    while (head!=NULL)
    {
        printf("№%d: %s\n",s, head->string);
        head = head->next;
        s++;
    }
}

void main(){
char massiv[1000],massiv1[1000],input[5],stroka[1000];
int q=1,l=1,i,Len=0,j,CommonLen=0,CommonLen1=0,scaniruem,k=0,n,count1=0,count2=0,flag = 0;
char a;
Node *tmp1, *tmp2;
memset(massiv,'\0',1000);
memset(massiv1,'\0',1000);
	while (q==1)
	{
	 printf("1)Создать пустой буфер\n");
	 printf("2)Инициализировать буфер строкой\n");
	 printf("3)Закрыть программу\n");
	 scanf("%d",&scaniruem);
	 switch (scaniruem)
	 {
	 case 2:
	 {
	  Len = 0;
	  k=0;
	  printf ("\nВведите строку\n");
	  while (isspace ((a = getchar ()))){}
	  while (a!='\n')
	  {
	   if (Len>999) {printf("Слишком длинная строка\n"); break;}
	   else
	   {
		massiv[CommonLen+Len]=a;
		Len++;
		a=getchar();
	   }
	  }
	  CommonLen=Len+CommonLen;

	  scaniruem = 1;
	 }
	 case 1:
	 {
	  Node*head=NULL;
	  printf("\nБуфер инициализирован\n");
	  while (l==1)
	  {
	   printf("1)Очистить строковый буфер\n");
	   printf("2)Добавить заданную строку в конец буфера\n");
	   printf("3)Вставить заданную строку с заданной позиции в буфере\n");
	   printf("4)Получить длину строки, накопленной в буфере\n");
	   printf("5)Скопировать строку из буфера в заданный символьный массив (по заданному указателю) - вставка в указанную позицию\n");
	   printf("6)Скопировать подстроку из буфера в заданный символьный массив (по заданному указателю) - замещение с указанной позиции\n");
	   printf("7)Получить символ в заданной позиции\n");
	   printf("8)Изменить символ в заданной позиции\n");
	   printf("9)Заменить одну подстроку в буфере на другую\n");
	   printf("10)Искать заданный символ(подстроку) в буфере\n");
	   printf("11)Обрезать накопленную строку по указанной длине\n");
	   printf("12)Закрыть программу\n");
	   scanf("%d",&scaniruem);
	   switch (scaniruem)
	   {
	   case 1:
	   {
	    deleteList(&head);
	    free(head);
	    printf("Буфер чист, сэр!\n");
	    memset(massiv,0,1000);
		CommonLen = 0;
	    break;
	   }
	   case 2:
	   {
	    scaniruem=0;
	    deleteList(&head);
	    Len = 0;
	    k=0;
	    printf ("\nВведите строку\n");
		while (isspace ((a = getchar ()))){}
		while (a!='\n')
		{
		 if (Len>999) {printf("Слишком длинная строка\n"); break;}
		 else
		 {
		  massiv[CommonLen+Len]=a;
		  Len++;
		  a=getchar();
		 }
		}
		CommonLen=Len+CommonLen;
		CommonLen1 = CommonLen;
		while (CommonLen1>0)
		{
		 for(i=0;i<5;i++)
		 {
		  if(massiv[k+i]=='\0'){break;}
		  input[i]=massiv[k+i];
		 }
		 k=k+5;
		 CommonLen1=CommonLen1-5;
		 if (head==NULL) {push(&head,input);} else {pushBack(head,input);}
		 memset(input,0,5);
		}
		printLinkedList(head);
		l=1;
		break;
	   }

	   case 3:
	   {
	    scaniruem=0;
	    deleteList(&head);
	    memset(massiv1,0,1000);
	    printf("Укажите позицию (порядковый номер элемента) для вставки, начиная с 1\n");
	    scanf("%d",&n);
	    n--;
	    if((n<0)||(n>CommonLen)){printf("Невозможно\n");}
	    else
	    {
	     Len = 0;
	     k=0;
	     i=0;
	     printf ("\nВведите строку\n");
		 while (isspace ((a = getchar ()))){}
		 while (a!='\n')
		 {
		  if (Len>999) {printf("Слишком длинная строка\n"); break;}
		  else
		  {
		   massiv1[Len]=a;
		   Len++;
		   a=getchar();
		  }
		 }
		 i=CommonLen-n;
		 for(k=0;k<1000;k++)
		 {
		  stroka[k]=massiv[k];
		 }
		 for(k=0;k<i;k++)
		 {
		  massiv[n+Len+k]=stroka[n+k];
		 }
		 //printf("%s\n",massiv);
		 k=0;
		 for(k=0;k<Len;k++)
		 {
		  massiv[n+k]=massiv1[k];
		 }
		 i=0;
		 CommonLen=Len+CommonLen;
		 CommonLen1 = CommonLen;
		 //printf("%s",massiv);
		 k=0;
		 while (CommonLen1>0)
		 {
		  for(i=0;i<5;i++)
		  {
		   if(massiv[k+i]=='\0'){break;}
		   input[i]=massiv[k+i];
		  }
		  k=k+5;
		  CommonLen1=CommonLen1-5;
		  if (head==NULL) {push(&head,input);} else {pushBack(head,input);}
		  memset(input,0,5);
		 }
		  printf("\n");
		 printLinkedList(head);
	     }
	    break;
	   }

	   case 4:
	   {
	    scaniruem=0;
	    printf("В буфере %d элемента(-ов)\n",CommonLen);
	    break;
	   }

	   case 5:
	   {
	    scaniruem=0;
	    Len=0;
	    k=0;
	    printf("Задайте символьный массив\n");
	    while (isspace ((a = getchar ()))){}
		while (a!='\n')
		{
		 if (Len>999) {printf("Слишком длинная строка\n"); break;}
		 else
		 {
		  stroka[Len]=a;
		  Len++;
		  a=getchar();
		 }
		}
		printf("Укажите позицию, куда нужно вставить строку из буфера\n");
		scanf("%d",&n);
		n--;
		if((n<0)||(n>Len)){printf("Невозможно\n");break;}

		i=CommonLen-n;
		 for(k=0;k<1000;k++)
		 {
		  massiv1[k]=stroka[k];
		 }
		 for(k=0;k<i;k++)
		 {
		  stroka[n+Len+k]=massiv1[n+k];
		 }
		 k=0;
		 for(k=0;k<Len;k++)
		 {
		  stroka[n+k]=massiv[k];
		 }
		 i=0;

		 printf("%s\n",stroka);
		 memset(stroka,0,1000);
	    break;
	   }

	   case 6:
	   {
	    scaniruem=0;
	    Len=0;
	    k=0;
	    printf("Задайте символьный массив\n");
	    while (isspace ((a = getchar ()))){}
		while (a!='\n')
		{
		 if (Len>999) {printf("Слишком длинная строка\n"); break;}
		 else
		 {
		  stroka[Len]=a;
		  Len++;
		  a=getchar();
		 }
		}
		printf("Укажите позицию, куда нужно вставить подстроку из буфера\n");
		scanf("%d",&n);
		n--;
		if((n<0)||(n>Len)){printf("Невозможно\n");break;}
		printf("Укажите номер подстроки\n");
		scanf("%d",&j);
		j--;
		if(((j>getAll(head))||(j<0))){printf("Невозможно\n"); break;}
		tmp2=getNth(head,j);

		for(k=0;k<1000;k++)
		 {
		  massiv1[k]=stroka[k];
		 }

		for(k=0;k<5;k++)
		 {
		  if(tmp2->string[k]=='\0'){k++;}
		  stroka[n+Len+k]=massiv1[n+k];
		  stroka[n+k]=tmp2->string[k];
		 }
		 printf("%s\n",stroka);
		 memset(stroka,0,1000);
	    break;
	   }

	   case 7:
	   {
	    scaniruem=0;
	    printf("Укажите позицию - порядковый номер элемента,значение которого необходимо получить( начиная с 1)\n");
	    scanf("%d",&n);
	    n--;
	    if((n<0)||(n>=CommonLen)){printf("Невозможно\n");}
	    else
	    {
	     printf("Значение элемента на %d позиции равно ''%c''\n",n+1,massiv[n]);
	    }
	    break;
	   }

	   case 8:
	   {
	    scaniruem=0;
	    printf("Укажите позицию - порядковый номер элемента,значение которого необходимо заменить( начиная с 1)\n");
	    scanf("%d",&n);
	    n--;
	    if((n<0)||(n>=CommonLen)){printf("Невозможно\n");}
	    else
	    {
	     printf("На какой символ необходимо заменить?\n");
	     while (isspace ((a = getchar ()))){}
	     massiv[n] = a;
	    }
	    deleteList(&head);
	    CommonLen1 = CommonLen;
		 k=0;
		 while (CommonLen1>0)
		 {
		  for(i=0;i<5;i++)
		  {
		   if(massiv[k+i]=='\0'){break;}
		   input[i]=massiv[k+i];
		  }
		  k=k+5;
		  CommonLen1=CommonLen1-5;
		  if (head==NULL) {push(&head,input);} else {pushBack(head,input);}
		  memset(input,0,5);
		 }
		 printLinkedList(head);
	    break;
	   }

	   case 9:
	   {
	    count1 = 0;
	    count2 = 0;
	    scaniruem=0;
	    printf("Введите номер первой подстроки:\n");
	    scanf("%d",&n);
	    printf("Введите номер второй подстроки:\n");
	    scanf("%d",&j);
	    if(((n>getAll(head))||(n<1))||((j>getAll(head))||(j<1))){printf("Невозможно\n"); break;}
	    else
	    {
	     if(n==j){printLinkedList(head); break;}
	     tmp1=getNth(head,n-1);
	     tmp2=getNth(head,j-1);
	     for(i=0;i<5;i++)
	     {
	     if (tmp1->string[i] != '\0')
	     count1++;
	     if (tmp2->string[i] != '\0')
	     count2++;
	     }
	     if (count1!=count2)
	     {
	      printf("Замена невозможна ввиду того, что длины не совпадают\n");
	      break;
	     }
	     for(i=0;i<5;i++)
	     {
	      input[i] = tmp1->string[i];
	      tmp1->string[i]=tmp2->string[i];
	      tmp2->string[i]=input[i];
	     }
	     printLinkedList(head);
	     k = 0;
	     tmp1 = head;
	     while (k<CommonLen)
	     {
	      for(i=0;i<5;i++)
	      {
	       if (tmp1->string[i]=='\0') break;
	       massiv[k+i] = tmp1->string[i];
	      }
	      k = k+5;
	      tmp1=tmp1->next;
	     }
	    }
	    memset(input,0,5);
	    break;
	   }

	   case 10:
	   {
	    scaniruem = 0;
	    k = 0;
	    Len = 0;
	    count1 = 0;
	    flag = 0;
	    memset(stroka,'\0',1000);
	    printf("Введите сроку для поиска совпадений\n");
	    while (isspace ((a = getchar ()))){}
		while (a!='\n')
		{
		 if (Len>999) {printf("Слишком длинная строка\n"); break;}
		 else
		 {
		  stroka[Len]=a;
		  Len++;
		  a=getchar();
		 }
		}
		while (k<=CommonLen-Len)
		{
		 for (i= 0;i<Len;i++)
		 {
		  if (massiv[k+i]==stroka[i]) count1++;
		 }
		 if (count1 == Len)  flag = 1;
		 k++;
		 count1 = 0;
		}
		if (flag !=1) printf("Совпадений не нашлось\n");
		else printf("Совпадение есть\n");
	    break;
	   }

	   case 11:
	   {
	    k = 0;
	   	scaniruem = 0;
	   	deleteList(&head);
	   	printf("Укажите длину, по которой необходимо обрезать буфер:\n");
	    scanf("%d",&n);
	    n--;
	    if((n<0)||(n>CommonLen)){printf("Невозможно\n");}
	    else
	    {

	    for (i=n;i<CommonLen;i++)
	    {
	     massiv[i] = '\0';
	    }
	    CommonLen = n;
	    printf("%s\n",massiv);
	    printf("Длина %d\n",CommonLen);
	    CommonLen1 = CommonLen;
		while (CommonLen1>0)
		{
		 for(i=0;i<5;i++)
		 {
		  if(massiv[k+i]=='\0'){break;}
		  input[i]=massiv[k+i];
		 }
		 k=k+5;
		 CommonLen1=CommonLen1-5;
		 if (head==NULL) {push(&head,input);} else {pushBack(head,input);}
		 memset(input,0,5);
		}
		printLinkedList(head);
		}
		break;
	   }
	   case 12:
	   {
	    scaniruem=0;
	    deleteList(&head);
	    free(head);
	    printf("Буфер чист, сэр!\n");
	    printf("Завершено\n");
	    return;
	   }
	   default:
	   {
	    break;
	   }
	   }
	  }
	  break;
	 }

	 case 3:
	 {
      printf("Завершено\n");
	  return;
	 }
	 default:
	 {
	  printf("\nНеверный выбор\n");
	  q=1;
	  break;
	 }
	 }
	}
}
