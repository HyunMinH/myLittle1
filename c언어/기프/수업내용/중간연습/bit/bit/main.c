//
//  main.c
//  bit
//
//  Created by 한현민 on 2016. 10. 17..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>

void prin(int);


int main(void){
    int a=10;
    int b;
    
    b=(~0);
    printf("%d \n\n", b);
    
    //b=a^(~0);
    b=~a;
    
    prin(a);
    printf("\n\n");
    prin(b);
    
}


void prin(int c){
    int cnt=0,i;
    for(i=31; i>=0; i--){
        printf("%d", ((c>>i)&1) ? 1 : 0 );
        
        
        cnt++;
        if(cnt%8==0) printf(" ");
    }

}