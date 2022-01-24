 #include<math.h>
#include<float.h>
void GAUS1(int lul,int* rk,double **matr);
void GAUS2(int lul,int* rk, double **matr);

void GAUS1(int lul,int* rk,double **matr)
{
	int c;
	int i,j;
    for(i=lul;i<*rk;i++)
		if(matr[i][lul]>0||matr[i][lul]<0)
			break;
	if (i==*rk)
		return;
	else if(i==lul)
		return;
		for(j=lul;j<*rk;j++)
		{
			c=matr[lul][j];
			matr[lul][j]=matr[i][j];
			matr[i][j]=c;
		}
}

void GAUS2(int lul,int* rk, double **matr)
{
	double k;
	int i,j,n,m;
	for(i=lul+1;i<*rk;i++)
		{
		  frexp(matr[i][lul],&n);
		  frexp(matr[lul][lul],&m);
		  if (((n-m)>1024)||((n-m)<(-1021)))
		  {
		    *rk=-1;
		    return ;
		  }
		   k=-matr[i][lul]/matr[lul][lul];
		   for(j=0;j<*rk;j++)
			{
			  frexp(matr[lul][lul],&n);
			  frexp(k,&m);
		    if (((n+m)>1024)||((n+m)<(-1021)))
		  {
		    *rk=-1;
		    return ;
		  }
			matr[i][j]=matr[lul][j]*k+matr[i][j];
		    }
	    }

} 

void GAUS1(int lul,int rk,double **matr);
void GAUS2(int lul,int rk, double **matr);

void GAUS1(int lul,int rk,double **matr)
{
	int c;
	int i,j;
    for(i=lul;i<rk;i++)
		if(matr[i][lul]>0||matr[i][lul]<0)
			break;
	if (i==rk)
		return;
	else if(i==lul)
		return;
		for(j=lul;j<rk;j++)
		{
			c=matr[lul][j];
			matr[lul][j]=matr[i][j];
			matr[i][j]=c;
		}
}

void GAUS2(int lul,int rk, double **matr)
{
	double k;
	int i,j;
	for(i=lul+1;i<rk;i++)
		{
		   k=-matr[i][lul]/matr[lul][lul];
		   for(j=0;j<rk;j++)
			{
			matr[i][j]=matr[lul][j]*k+matr[i][j];
		    }
	    }

}
void GAUS1(int lul,int rk,double **matr);
void GAUS2(int lul,int rk, double **matr);

void GAUS1(int lul,int rk,double **matr)
{
	int c;
	int i,j;
    for(i=lul;i<rk;i++)
		if(matr[i][lul]>0||matr[i][lul]<0)
			break;
	if (i==rk)
		return;
	else if(i==lul)
		return;
		for(j=lul;j<rk;j++)
		{
			c=matr[lul][j];
			matr[lul][j]=matr[i][j];
			matr[i][j]=c;
		}
}

void GAUS2(int lul,int rk, double **matr)
{
	double k;
	int i,j;
	for(i=lul+1;i<rk;i++)
		{
		   k=-matr[i][lul]/matr[lul][lul];
		   for(j=0;j<rk;j++)
			{
			matr[i][j]=matr[lul][j]*k+matr[i][j];
		    }
	    }

}

void GAUS1(int lul,int rk,double **matr)
{
	int c;
	int i,j;
    for(i=lul;i<rk;i++)
		if(matr[i][lul]!=0)
			break;
	if (i==rk)
		return;
	else if(i==lul)
		return;
		for(j=lul;j<rk;j++)
		{
			c=matr[lul][j];
			matr[lul][j]=matr[i][j];
			matr[i][j]=c;
		}
}

void GAUS2(int lul,int rk, double **matr)
{
	double k;
	int i,j;
	for(i=lul+1;i<rk;i++)
		{
		   k=-matr[i][lul]/matr[lul][lul];
		   for(j=0;j<rk;j++)
			{
			matr[i][j]=matr[lul][j]*k+matr[i][j];
		    }
	    }

}







