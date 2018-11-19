#include <stdio.h>



void arraymerge(int *a,int an,int *b,int bn,int*c)
{
    int x=0,y=0,z=0;
    while(1)
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
        else if(z==an+bn)
            break;
        
        
    }
}



int main(void)
{
    int a[]={1,2,5,7,9,14};
    int b[]={2,3,6,8,13};
    int c[11] = {0};
    int i;
    arraymerge(a,6,b,5,c);
    printf("배열 출력\n");
    
    for(i=0;i<11;i++)
        printf("%d  ",c[i]);
    
}
