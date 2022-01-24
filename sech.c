#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <string.h>

int read(double *a);
double f(double x/*, int *h*/);

int main (void) {
  int q, i=0;
  double a, b, e, g, j, x1, x2, x3, x, phi;
  phi=((1+sqrt(5))/2);
printf("Enter the value of the left bound a:");
q=read(&a);
if (q==-1){
  printf("Incorrect input \n");
  return -1;
}
printf("Enter the value of right bound b:");
q=read (&b);
if (q==-1){
  printf("Incorrect input \n");
  return -1;
}
   /*  if (a>=DBL_MAX ) { printf("Value error \n"); return -1; }
     if (b>=DBL_MAX ) { printf("Value error \n"); return -1; }
     if (a<=DBL_MIN ) { printf("Value error \n"); return -1; }
     if (b<=DBL_MIN ) { printf("Value error \n"); return -1; }*/

if ((a<=b) && (b<=a)) {
        printf("Empty %e \n", a );
        return -1;
        }

if(a>b){
	 	g=a;
		j=b;
		b=g;
		a=j;
	    }


printf("Enter the accuracy e:");
q=read (&e);
if (q >= -1 && q <= -1){
  printf("Incorrect input \n");
  return -1;
}

if (e<=0){
        printf("Negative accuracy \n");
        return -1;
        }
 x1=b-((b-a)/phi);
 x2=a+((b-a)/phi);
        
	if (f(x1)>f(x2)) {
	    a=x1;
	}
	  else {
        b=x2;};
	
/*y2=f(b);

here:	
 x3=a+((b-a)/phi);
	   if (f(x3)>y2) {
	    a=x3;
	    i++;}
	   else {
        b=x3;
	    i++;};
	    
if (b<(e+a)) {x=(a+b)/2;
            printf("Solution: %e, Iterations number: %d \n", x,i);
return 0;}
else {goto here;};
}
*/

while (b-a>e) {
  x3=a+((b-a)/phi);
      if (((a<=b) && (b<=a)) || ((a<=x3) && (x3<=a)) || ((b<=x3) && (x3<=b))) {
	printf ("Accuracy error \n");
	return -1;
        }
  if (f(x3)>f(b)) {
	    a=x3;
	    i++;}
	   else {
        b=x3;
	    i++;};
//x=(a+b)/2;
     if (f(a)<=f(b)) {x=a;}
     else {x=b;}
     if (a>=DBL_MAX ) { printf("Value error \n"); break; }
     if (b>=DBL_MAX ) { printf("Value error \n"); break; }
     if (a<=DBL_MIN ) { printf("Value error \n"); break; }
     if (b<=DBL_MIN ) { printf("Value error \n"); break; }
}
printf("Solution: %e, Iterations number: %d \n", x,i);
return 0;
  
}


 double f(double x/*, int *h*/) {
 /*  if  (x*x*x-9*x*x-81*x+729) < sqrt(DBL_MAX)) */

  /* if (x>=log(DBL_MAX)){
     *h = 1;
     return -1;
   }
   else {*h=0; */
  // *h=0;
   return sin(x);
   }


   int read(double *a){
double X = 0;
    int  j = 0, flag0 = 0, N = 0;
    int  sizex = 0, dot1 = 0;

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
    sizex = strlen(numX);
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
    memset(numX, '\0', sizeof(int)*sizex);
    *a = X;
    return 10;
}
