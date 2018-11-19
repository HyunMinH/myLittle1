#include <stdio.h>

void printArray(int a[][10],int rows, int cols)
{
    int i,j;
    
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}


void multiply(int a[][10], int b[][10], int c[][10],int size)
{
    int i,j,k;
    
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            c[i][j]=0;
            for(k=0;k<size;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}


int main()
{
    int i,j,n;
    int A[10][10];
    int B[10][10];
    int C[10][10];
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    multiply(A,B,C,n);
    printArray(C,n,n);
    
}
