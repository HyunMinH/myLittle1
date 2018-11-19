//
//  main.c
//  쿼드 트리 뒤집기1
//
//  Created by 한현민 on 2016. 9. 30..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>
#include <string.h>

void printch(char vc[][4], int num_vc){
    int i;
    
    for(i=0; i<4; i++){
        printf("%c", vc[num_vc][i]);
        if (vc[num_vc][i]=='x') printch(vc, num_vc+1);
    } printf("\n");
}


void check(char vc[][4], char ch[], int num_ch, int num_vc){
    int i;
    
    for (i=0; (strlen(ch)>=4) ? i<4 : i<strlen(ch); i++){
        vc[num_vc][i]= ch[num_ch];
        if (ch[num_ch]++ == 'x') check(vc, ch, num_ch, num_vc+1);
    } printch(vc, 0);
}


int main(void){
    char vc[][4]={}, ch[]={};
    
    printf("문자열을 입력하시오: ");
    scanf("%s", ch);
    
    check(vc, ch, 0, 0);
}