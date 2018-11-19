//
//  main.c
//  pointer and ary
//
//  Created by 한현민 on 2016. 10. 17..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>

#define CENTER(n) ('a'+(n+1)/2-1)


int scan(){
    int rownum;
    
    while(1){
        printf("몇 줄로 하실껍니까?(0보다 크고 홀수여야 함!):");
        scanf("%d", &rownum);
        
        if(rownum>0 && rownum%2==1) break;
        else printf("다시 입력하세요. \n");
    }
    
    return rownum;
}


void prin(int rownum){
    int y, x, limit;
    
    for(y='a', limit=0; y<rownum+'a'; y++){
        
        for(x='a'; x<rownum+'a'; x++){
            
            if(x>=CENTER(rownum)-limit && x<=CENTER(rownum)+limit){
                printf("%c ", x);
            }else printf("  ");
            
        }
        printf("\n");
        
        if(y>=CENTER(rownum)) limit--;
        else limit++;
    }
    
}


int main(void){
    
    prin(scan());
    
    return 0;
}