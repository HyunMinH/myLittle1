//
//  main.c
//  1010 8퀸
//
//  Created by 한현민 on 2016. 10. 10..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>


void setQueen(int, int);

int arr[8];
int a = 0;
int *vc = &a;
//int *num=0;


int cheakIFHereOk(int y, int x){
    int i, ret = 0; // ret는 return할 값;
    
    for(i=0; i<y; i++){
        if(arr[i]==x) ret++;
        else if(arr[i]+(y-i)==x) ret++;
        else if(arr[i]-(y-i)==x) ret++;
    }
    return ret;
}


void prinElement(int y, int x){
    if(arr[y] == x) printf("■ ");
    else printf("□ ");
}


void prinArr(){
    int y, x;
    
    for(y = 0; y < 8; y++){
        for(x = 0; x < 8; x++)
            prinElement(y, x);
        printf("\n");
    }
}


void IFsucceed(){
    prinArr();
    *vc= *vc+1;
    printf(" \n\n");
    if(arr[6]==8) return;
    setQueen(6, arr[6]+1);
}


void setQueen(int y, int x){
    if(y == -1)return;
    
    if(y == 8){
        IFsucceed();
        return;
    }else if(x == 8){
        setQueen(y-1, arr[y-1]+1);
        return;
    }
    
    if(cheakIFHereOk(y, x) == 0){
        arr[y]=x;
        setQueen(y+1, 0);
    }else setQueen(y, x+1);
}


void arrInit(){
    int i;
    
    for(i = 0; i < 8; i++) arr[i]=-1;
}


int main(void){
    arrInit();
    
    setQueen(0,0);
    printf("%d\n", a);
}
