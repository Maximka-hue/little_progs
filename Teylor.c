#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <float.h>

int scaninput(char *a);
int bignum(char *c);
double reduce(double x, int *exp);
double logg(double x, double eps);
double reduce(double x,int *exp)
{
  double z;
  int i = 0;
  printf("Caught number outside of 0.5 < x < 1 range\n");
  z = x;
  if(z > 1.0)
  {
    while (z > 1.0)
  {
    
    z = z/2.0;
    i++;
  }
  }
  else
    while (z < 0.5)
  {
    
    z = z*2.0;
    i--;
  }
  *exp = i;
  return z;
}
double logg(double x, double eps)
{
  double result = 0.0, term = 0.0;
  int powerofone = -1, i = 1;
  long int denominator = 2;
  double temp;
  
    term = x - 1;
    temp = term;
  while ((temp > eps) || (-temp > eps))
  {
    if(temp > eps)
    {
      result -= temp;
    }
    else 
    {
      result += temp;
    }
    printf("current term %.15e           %d\n", temp, i);
    term = term * (x - 1);
    temp = term * powerofone; 
    temp /= denominator;
    powerofone *= -1;
    denominator += 1;
    i++;
  }
  i++;
  result += term;
  printf("current term %.15e           %d\n", temp, i);
  return result;
}
int main(void)
{
    double a, eps, x, f, b,c;
    int exp;
    char *ptrEND1, *ptrEND2;
    char A[258];
    char e[258];
    exp = 0;
    printf("Please enter number:\n");  
    scaninput(A);
	if(A[0]=='\0') {printf("You pressed just enter\n"); return -1;}
    if(bignum(A) == -1) {printf("Error range input\n"); return -1;}
    a = strtod(A, &ptrEND1);
    if(strlen(ptrEND1) != 0)
    {
        printf("Input error |%s|\n", ptrEND1);
        return -1;
    }
    if((a <= 0) && (a >= 0)) {printf("Error range input\n"); return -1;}
    if (a < 0) {printf("Error range input\n"); return -1;}
    printf("Please enter epsilon:\n");
    scaninput(e);
    if(e[0]=='\0') {printf("You pressed just enter\n"); return -1;}
    if(bignum(e) == -1) {printf("Error range input\n"); return -1;}
    eps = strtod(e, &ptrEND2);
    if(strlen(ptrEND2) != 0){printf("error, |%s|\n", ptrEND1);return -1;}
    if ((eps >= 1)||(eps<0)) {printf("Error epsilon input.\n"); return -1;}
    
    if ((a > 1.0) || (a < 0.5))
    {
      x = reduce(a, &exp);
      b = logg(0.5, eps);
      printf("log2 == %.15e\n", b);
      c = logg(x, eps);
      f = c + exp * (-1) * b;
    }
    else
      f = logg(a, eps);
    printf("Result == %.15e\n", f);
    printf("<math.h> == %.15e\n", log(a));
    printf("%.15e      \n", fabs(log(a) - f));
    return 0;
}



int scaninput(char *a)
{
    int i=0, j=0;
    char ch;
    do
    {
        ch=getchar();
        if(i<256)
        {
        if(ch!='\n')a[i]=ch;
        i++;
        }
        j++;
        if(j>=256)
    {
      printf("%d\n", j);
      printf("error stdin overflow\n");
      exit(EXIT_FAILURE);
    }
    }
    while(ch!='\n');
    a[i-1]='\0';
    return 1;
}
int bignum (char *c)
{
int j, size=0, save=0;
char *num;
char *ost;
float y;
char b[258];
double u;
double q;
size = strlen(c);
for( j=0; j < size;j++)
{
if( (c[j]=='E')||(c[j]=='e') )
{
save=j;
break;
}
}
if (save>0)
{
num = &c[save+1];
}
else {return 0; }
y=strtod(num, &ost);
if ((y<=0)&&(y>=0))
{return 0;}
if ((y>308) || (y < -308))
{
printf ("\n %s = Range input Error. \n  \n", c);
return -1;
}
if ((y <= 308) || (y >= -308))
{
  memcpy(b, c, (j));
  
  u = strtod(b, NULL); 
}
q = log10(fabs(u)) + fabs(y);
if((fabs(u) > 1.7) || (q > (log10(1.7) + 308))) {printf("This number exceeds range of double!\n"); return -1;}
return 0;
}
