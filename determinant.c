#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include"main.h"
int poryadok(void);
int read(double *x);

void DETERMINANT(int rk,double **matr);


int main(void)
{
	int N;
	double ** A;
	int shetchik=0;
	printf("PORYADOK= ");
	N=poryadok();
	if (N==-1)return -1;
	A=(double**)calloc(N,sizeof(double*));
	if (A==NULL) return -1;
	for(int i=0;i<N;i++)
		A[i]=(double*)calloc(N,sizeof(double));
	for(int i=0;i<N;i++)
	  for(int j=0;j<N;j++)
	  {
	    printf("ENTER A[%d][%d]=",i,j);
	    if (read(&A[i][j])==-1)
	      return -1;
	  }
	while(shetchik<N)
	{
    GAUS1(shetchik,&N,A);
	if (A[shetchik][shetchik]>=0&&A[shetchik][shetchik]<=0)                                               
		     shetchik++;
	else
	 {
		GAUS2(shetchik,&N,A);
		if (N==-1)
		{
		  printf("ERROR\n");
		  return 0;
		}
		shetchik++;
	 }
	} 
   DETERMINAND(N,A);
   if (N==-1)
   {
     printf("ERROR");
     return 0;
   }
     for(int i=0;i<N;i++)
       free(A[i]);
     free(A);
	
	
	return 0;	
}


int poryadok(void)
{ 
int x; 
int A[10]; 
int i=0; 
int j=1;  
int chislo; 

while((x=getchar())!='\n') 
{ 

if(x!='1'&&x!='2'&&x!='3'&&x!='4'&&x!='0'&&x!='5'&&x!='6'&&x!='7'&&x!='8'&&x!='9') 
{ 
printf("Ne pravilnoe chislo"); 
return -1; 
} 
x=x-'0'; 
A[i]=x; 
if(A[0]==0) 
{ 
while(A[0]==0) 
{ 

x=getchar(); 
if(x=='\n')  return -1; 
x=x-48; 
A[0]=x; 
} 
} 
i++; 
if(i==9) 
{ 
printf("ERROR\n"); 
return -1; 
} 
} 
if(i!=1) 
{ 
while(j<i) 
{ 
A[j]=A[j-1]*10+A[j]; 
j++; 
} 
chislo=A[i-1]; 
} 
else chislo=A[i-1]; 
return chislo; 
} 
int read(double *a){
double X = 0;
    int  j = 0, flag0 = 0, N = 0;
    int  sizex = 0, dot1 = 0;
    //ввод имени файла и его открытие
    char numX[256];
    int  in = 1;
    char* err1;


while((in = getchar())!='\n')
    {
        if(in != '0')
        {
            flag0 = 1;
        }
        if(in == '.')
        {
            dot1 = in;
        }
        numX[j] = in;
        if(numX[j] == '0' && flag0 == 0)
        {
            j--;
        }
        j++;
        if(j == 256)
        {
            break;
        }
    }
    numX[j+1] = '\0';
    sizex = abs(strlen(numX));
    if(dot1 != 0)
    {
        if((sizex - dot1) > 16)
        {
            printf("Incorrect number in file.!!!\n");
            return -1;
        }
    }
    if (sizex > 250 && numX[j - 1] != '\0'){
        printf("Big number1\n");
        return -1;
    }
    while (sizex > N){
       if ( numX[N] == 'e' || numX[N] == 'E' ){
	 while (numX[N+1] == '0' || numX[N+1] == '+' || numX[N+1] == '-'){ N++; }
	     if ( numX[N+4] != '\0' ) {
		 printf("Big number2\n");
                 return -1;
	      }
               if ( numX[N+3] != '\0' ){
                    if ( ( (int)(numX[N+1] - '0')*100 + (int)(numX[N+2] - '0')*10 + (int)(numX[N+3] - '0') ) > 308.5){
                        printf("Big number3\n");
                        return -1;
                    }
                }
        }
        N++;
    }
    while(numX[sizex - 1] == '0')
    {
      sizex--;
    }
    X = strtod(numX, &err1);
    printf("%0.15lf\n", X);
    if(errno == EDOM || errno == ERANGE)
    {
        printf("N is not a namber.\n");
        return -1;
    }
    memset(numX, '\0', sizeof(int)*sizex);
    *a = X;
    return 10;
}

void DETERMINANT(int rk,double **matr)
{
	double DET=1.0;
    for(int i=0;i<rk;i++)
    {
		DET=matr[i][i]*DET;
    }
	printf("DETERMINAND= %lf \n   ",DET);
}
