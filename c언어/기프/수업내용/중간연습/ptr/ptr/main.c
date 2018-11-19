#include <stdio.h>



int main(void){
    int ary[][4]={1,2,3,4,5,6,7,8};
    int (*ptr)[4]=ary;
    
    printf("%d  %d  ", **(ary+1), **(ptr++));
    

    
}

