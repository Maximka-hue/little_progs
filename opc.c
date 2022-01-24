 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <string.h>

int read(double *x);
double fun(double, int*);


double fun(double x, int * h) 
{
    double f = 0;
    if (x>=pow(DBL_MAX, 0.5))
     { printf("input smaller limits 2 \n"); *h = 1; }

else {
    f = x*x-4*x+9;
    *h = 0;}
	return f;

}

int main(void)
{
	double  result, a, b, *mas_x, *mas_y, tmp, x, y, k,rez1,rez2, calc1, calc2;
	int fl, i=0,  j, index,q,ch1, ch2,n;


	printf("Please input the number of points \n =>");
	fl = scanf("%d", &n);
	if (fl != 1)
	{
		printf("input error (n).\n");
		return -1;
	} 
	if (n <=1 ) {printf("not enought \n"); return -1;}

	mas_x = (double*)malloc((n+1)*sizeof(double));
	mas_y = (double*)malloc(n*sizeof(double));
	if (n > 10000|| errno== ENOMEM)
	{
		printf("error; Memory\n");
		return -1;
	}

	printf("Input x_i \n");
	for (i = 0; i < n; i++)
	{
		printf("=>");
		fl=scanf("%lf", &mas_x[i]);
		if (fl != 1)
		{
			printf("input error: fl!= 1.\n");
			return -1;
		}
	
		/*
		printf("=>");
			q = read(&mas_x[n+1]);
	
		q = read(&mas_x[i]);
		//printf("wwefawefawef");
		if (q == -1)
		{
		printf("necorectni.\n");
		return -1;
		}
*/

	/*	for (i = 0; i < n; i++)
	{
		printf("=>");
		fl=scanf("%lf", &mas_x[i]);
		if (fl != 1)
		{
			printf("input error: fl!= 1.\n");
			return -1;
		}
*/
		if ((fpclassify(mas_x[i]) == FP_SUBNORMAL) || (fpclassify(mas_x[i]) == FP_INFINITE)) // not chislo, + - infinity
		{
			printf("error: x_%d is infinity or subnormal\n",i);
			return-1;
		}
	}

	
	printf("\n And input y_i:\n");
	for (i = 0; i < n; i++)
	{
		/*printf("=>");
		q = read(&mas_y[i]);
		if (q == -1)
		{
		printf("necorectni.\n");
		return -1;
		}
*/
		 printf("=>");
		fl = scanf("%lf", &mas_y[i]);
		if (fl != 1)
		{
			printf("input error: fl!= 1.\n");
			return -1;
		}

		if ((fpclassify(mas_y[i]) == FP_SUBNORMAL) || (fpclassify(mas_y[i]) == FP_INFINITE))
		{
			printf("error: y_%d is infinity or subnormal\n", i);
			return-1;
		}
	}

	////////////////////////////////sort
	for (i = 0; i < n; i++)	
	{
		for (j = i + 1; j < n; j++)
		{
			if (mas_x[j] < mas_x[i])
			{
				tmp = mas_x[i];
				mas_x[i] = mas_x[j];
				mas_x[j] = tmp;

				tmp = mas_y[i];
				mas_y[i] = mas_y[j];
				mas_y[j] = tmp;
			}

			if ((mas_x[j] <= mas_x[i]) && (mas_x[j] >= mas_x[i]))
			{
				printf("error: x_%d = x%d it must be different \n", i, j);
				return -1;
			}
		}
	}


	a = mas_x[0];
	b = mas_x[n-1];


	/*printf("Input x:  ");
	q = read(&x);
	if (q == -1)
	{
		printf("necorectni.\n");
		return -1;
	
*/

	printf("Input x:  ");
	fl = scanf("%lf", &x);
	if (fl != 1)
	{
		printf("input error: fl!= 1.\n");
		return -1;
	}
	
	if ((fpclassify(x) == FP_SUBNORMAL) || (fpclassify(x) == FP_INFINITE))
	{
		printf("error: x is infinity or subnormal\n");
		return-1;
	}



	if (x<a || x>b)
	{
		printf("error: x<a or x>b; \n");
		return -1;
	}

	index = 0;
	for (i = 0; i < n - 1; i++)
	{
		if ((x >= mas_x[i]) && (x <= mas_x[i + 1]))
		{
			index = i;
			i += n;
		}
	}

 		frexp(mas_y[index] - mas_y[index + 1],&ch1);
		frexp(mas_x[index] - mas_x[index + 1],&ch2);
		  if (((ch1-ch2)>1024)||((ch1-ch2)<(-1021)))
		  {
		    printf("bad numbers \n "); 
		    return -1 ;
		  }


	if (mas_y[index] >= mas_y[index + 1]) {calc1 = mas_y[index]; calc2 =mas_y[index + 1]; } else {calc2 = mas_y[index]; calc1 =mas_y[index + 1]; } 

	if (calc1>calc2+DBL_MIN) {} else {printf("erroreeeeee 1\n"); return -1; }

	if (mas_x[index] >= mas_x[index + 1]) {calc1 = mas_x[index]; calc2 =mas_x[index + 1]; } else {calc2 = mas_x[index + 1]; calc1 =mas_y[index]; } 

	//if (calc1>calc2+DBL_MIN) {} else {printf("erroreeeeee 2\n"); return -1; }

	k = (mas_y[index] - mas_y[index + 1]) / (mas_x[index] - mas_x[index + 1]);

		
 		frexp(mas_x[index],&ch1);
		frexp(mas_y[index + 1],&ch2);
		  if (((ch1-ch2)>1024)||((ch1-ch2)<(-1021)))
		  {
		    printf("bad numbers1 \n "); 
		    return -1 ;
		  }		else rez1 = mas_x[index] * mas_y[index + 1] ;

		frexp(mas_y[index],&ch1);
		frexp(mas_x[index + 1],&ch2);
		  if (((ch1-ch2)>1024)||((ch1-ch2)<(-1021)))
		  {
		    printf("bad numbers2\n "); 
		    return -1 ;
		  }		else rez2 = mas_y[index] * mas_x[index + 1] ;

		frexp(rez1-rez2,&ch1);
		frexp(mas_x[index] - mas_x[index + 1],&ch2);
		  if (((ch1-ch2)>1024)||((ch1-ch2)<(-1021)))
		  {
		    printf("bad numbers3 \n "); 
		    return -1 ;
		  }	
		

	b = (mas_x[index] * mas_y[index + 1] - mas_y[index] * mas_x[index + 1]) / (mas_x[index] - mas_x[index + 1]);
	
		frexp(k,&ch1);
		frexp(x,&ch2);
		  if (((ch1-ch2)>1024)||((ch1-ch2)<(-1021)))
		  {
		    printf("bad numbers4 \n "); 
		    return -1 ;
		  }	

	y = k*x + b;
q = 0;
result = fun(x, &q);
if(q == 1)
     {
        printf("odz1\n");
        return -1;
     }

	printf("f(x) by method = %lf;\n\n", y);
	printf("f(x) by formula = %lf.\n", result);
	return 0;
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

