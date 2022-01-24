#include "func.h"

double remember;
int count=0;

int func(double** matrix, int N, int M)
{
    int i=0, j=0, k=0, holdint=0, holdi=0, holdj=M, rank=N;
    double hold=0, sum=0;
    clock_t time;

    count++;
    if(N>M)
    {
        holdint=N;
        N=M;
        M=holdint;
    }
    time=clock();
    for(k=0;k<N-1;k++)
    {
        for(i=k;i<N;i++)
        {
            for(j=k;j<M;j++)
            {
                if(fabs(matrix[i][j])>0 && j<holdj)
                {
                    holdi=i;
                    holdj=j;
                    break;
                }
            }
        }
        if(holdi!=k)
        {
            for(j=holdj;j<M;j++)
            {
                 errno=0;
                 matrix[k][j]+=matrix[holdi][j];
                 if(errno==EDOM || errno==ERANGE)
                 {
                     printf("Sum of elements is not double (1).\n");
                     exit(-1);
                 }    
            }
        }
        for(i=(N-1);i>k;i--)
        {
            if((fabs(matrix[i][holdj])<fabs(matrix[k][holdj])) && fabs(matrix[i][holdj])>0)
            {
                for(j=holdj;j<M;j++)
                {
                     hold=matrix[k][j];
                     matrix[k][j]=matrix[i][j];
                     matrix[i][j]=hold;
                }
            }
        }
        for(i=k+1;i<N;i++)
        {
            if(fabs(matrix[i][holdj])>0)
            {
                hold=matrix[i][holdj];
                for(j=holdj;j<M;j++)
                {
                    errno=0;
                    matrix[i][j]+=(-hold)*(matrix[k][j]/matrix[k][holdj]);
                    if(errno==EDOM || errno==ERANGE)
                    {
                        printf("Sum of elements is not double (2).\n");
                        exit(-1);
                    }    
                }
            }
        }
        holdi=0, holdj=M;
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            errno=0;
            sum+=matrix[i][j];
            if(errno==EDOM || errno==ERANGE)
            {
                 printf("Sum of elements is not double (3).\n");
                 exit(-1);
            }    
        }
        if(sum<=0 && sum>=0)
        {
            rank--;
        }
        sum=0;
    }
    time=clock()-time;
    if(time>0)
    {
        printf("Calculation time of rank: %f seconds\n", (double)time/CLOCKS_PER_SEC);
        if(count==1) remember=(double)time/CLOCKS_PER_SEC;
        if(count==2) printf("Ratio of times: %f\n", (double)(time/CLOCKS_PER_SEC)/remember);
    }
    for(i=0;i<N;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return rank;
}
