#include <stdio.h>
#include <stdlib.h>

void arraymerge(int *a,int an,int *b,int bn,int*c)
{
    int x=0,y=0,z=0,i;
    while(x!=an&&y!=bn)
    {
        if(a[x]==b[y])
        {
            c[z]=a[x];
            x=x+1;
            z=z+1;
            c[z]=b[y];
            y=y+1;
            z=z+1;
            
        }
        else if(a[x]<b[y])
        {
            c[z]=a[x];
            x=x+1;
            z=z+1;
            
        }
        else if(a[x]>b[y])
        {
            c[z]=b[y];
            y=y+1;
            z=z+1;
        }
    }
    if(an>bn)
    {
        for(i=x;i<an;i++)
        {
            c[z]=a[x];
            z=z+1;
            x=x+1;
        }
    }
    else if(an<bn)
    {
        for(i=y;i<bn;i++)
        {
            c[z]=a[y];
            z=z+1;
            y=y+1;
        }
    }
}



int main(void)
{
    int a[]={1,2,5,7,9,14};
    int b[]={2,3,6,8,13};
    int c[11];
    int i;
    arraymerge(a,6,b,5,c);
    printf("합병배열 출력:");
    
    for(i=0;i<11;i++)
        printf("%d  ",c[i]);
    
}
