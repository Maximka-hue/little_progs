#include<stdio.h>
#include<math.h>
#include<float.h>
#include<errno.h>
#include<stdlib.h>
double fact(double x);
double sintaylor(double tochka,double y,double stepen,int minus);
double perevod(double tochka);
int main(void)
{
	int znak=1,i=0;
	char A[256];
	double y=3.0,x,E,chislo,chlen,kik,real;
	printf ("tochka tochonst-->tochk�\n");
    while((A[i]=getchar())!='\n')
	{
		i++;
	}
	x=strtod(A,NULL);
      if(errno!=0)
		{
			printf("ERRR\n");
			return -1;
		}
	real=sin(x);
	x=perevod(x);
	if (x==-20)
	{
		printf("ERROR\n");
		return -1;
	}
	i=0;
	while((A[i]=getchar())!='\n')
	{
		i++;
	}
	E=strtod(A,NULL);
	if(errno!=0)
		{
			printf("ERRR\n");
			return -1;
		}
	chislo=x;
	if(E>1)
	{
		printf("ERROR\n");
		return -1;
	}
    do
	{
		kik=fact(y);
		if (kik==-1){
			printf("TOO SMALL E\n");
			return -1;
		}
		chlen=sintaylor(x,kik,y,znak);
		if (chlen==-2.28){
			printf("TOO SMALL E\n");
			return -1;}
		chislo=chislo+chlen;
		y=y+2.0;
		znak++;
	}while(fabs(chlen)>E);
		printf("%.20lf\n",chislo);
	    printf("REAL ANSWER = %.20lf\n",real);

	return 0;
}


double fact(double x)
{
	int e1,e2;
	double j=1,i=1,b;
	for(b=1;b<=x;b++)
	{
		i=b;
		frexp(i,&e1);
		frexp(j,&e2);
		if((e1+e2)>=1020)
			return j=-1.0;
		i=i*j;
		j=i;
	}
	return j;
}

double sintaylor(double tochka,double y,double stepen,int minus)
{
	double znak=-1,kek;
	int fak,lyl;
	frexp(tochka,&fak);
	frexp(y,&lyl);
	fak=fak*stepen;
	if((fak-lyl)>1020||(fak-lyl)<-920)
		return -2.28;
	znak=pow(znak,minus);
	kek=pow(tochka,stepen);
	kek=znak*kek/y;
	return kek;
}
double perevod(double tochka)
{
	double fi=180,PI=3.141592653589793238462643;
	int j,i,k;
	frexp(PI,&k);
	frexp(tochka,&j);
    frexp(fi,&i);
	if ((j+i-k)>1020||(j+i-k)<-900)
		return -20;
	fi=tochka*fi/PI;
	if (fi<=(-2*PI))
	{
		while(fi<=-180.0)
		{
			fi=fi+180.0;
		}
		fi=fi*PI/180;
		return fi;
	}
	else if (fi>=2*PI)
	{
		while(fi>=2*PI)
		{
			fi=fi-180;
		}
		fi=fi*PI/180;
		return fi;
	}
	else
	{
		fi=fi*PI/180;
		return fi;
	}
}
