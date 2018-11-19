//
//  main.c
//  암호화
//
//  Created by 한현민 on 2016. 9. 30..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(void){
    char code1[]="JMARTYVWBDLQNCXGZEKIPUFOHS";
    char code2[]="abcdefghijklmnopqrstuvwxyz";
    char scancode[]={};
    int i=0, j, a=0;
    
    scanf("%s", scancode);
    
    while(1){
        for (j=0; j<26; j++)
            if (scancode[i] == code1[j]) a=j;
        
        printf("%c", code2[a]);
        if (i++>=strlen(scancode)) break;
    }
}