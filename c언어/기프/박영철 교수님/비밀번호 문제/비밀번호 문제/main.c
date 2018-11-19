//
//  main.c
//  비밀번호 문제
//
//  Created by 한현민 on 2016. 10. 6..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void){
    
    char a[11]={};
    char b[11]={};
    int i, index=0;
    
    
   while(1){
       
       while(1){
           printf("비밀번호를 입력하시오(최소 5자리, 최대 10자리): ");
           scanf("%s", a);
           fflush(stdin);
       
           for(i=0; i<strlen(a); i++) printf("*");
       
           if(strlen(a)<5 || strlen(a)>10) printf("오류!!! 비밀번호의 크기가 틀렸습니다. 다시 시도하세요. \n");
           else break;
       }// 첫 번째 비밀번호 설정
       
       while(1){
           printf("\n비밀번호를 한번 더 입력하시오(최소 5자리, 최대 10자리): ");
           scanf("%s", b);
           fflush(stdin);
       
           for(i=0; i<strlen(b); i++) printf("*");
    
           if(strlen(b)<5 || strlen(b)>10) printf("오류!!! 비밀번호의 크기가 틀렸습니다. 다시 시도하세요. \n");
           else break;
       }
       
        if(strlen(a)==strlen(b)){
            for(i=0; i<strlen(a); i++){
                if(a[i]==b[i]) index++;
            }
            if(index == strlen(a)){
                printf("당신이 입력한 비밀번호는 %s입니다. \n", a);
                break;
            }else printf("오류!!! 비밀번호가 틀렸습니다. 다시 시도하세요. \n");
           
        }else{
            printf("오류!!! 비밀번호의 크기가 서로 다릅니다. 다시 시도하세요. \n");
        }
       
   }
    return 0;
}