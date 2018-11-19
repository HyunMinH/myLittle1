//
//  main.c
//  창묵2
//
//  Created by 한현민 on 2016. 10. 9..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>

int main()
{
    
int j;
int i=0x3C405B7B;
char ch;
char *p=(char *)&i;

for(j=-1;j<=2;j++)
{
    ch=*(p+j+1);
    printf("%2c %p\n",ch,p+j);
}

}