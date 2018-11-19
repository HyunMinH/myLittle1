//
//  main.c
//  이우진 배열
//
//  Created by 한현민 on 2016. 10. 12..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>

int arr[100];
int a=0, *idx=&a;


void display(){
    int i=0;
    
    printf("Array[%d]={", *idx);
    if(*idx==0) printf(" }\n");
    else{
        for(i=1;i<=*idx;i++) printf(" %d", arr[i]);
        printf(" }\n");
    }
}



int find(int value){
    int i;
    
    for(i=1; i<=*idx; i++)
        if(arr[i]==value) break;
        
    if(i>*idx) return -1;
    else return i;
}



void delete(){
    int fnum, i;
    
    printf("뭘 없앨꺼야: "); scanf("%d", &fnum);
    if(find(fnum)==-1) printf("no\n");
    else{
        for(i=find(fnum); i<=*idx; i++) arr[i]=arr[i+1];
        arr[*idx]=-1;
        *idx=*idx-1;
    }
    
    
}



void selec(){
    int num, warn_num=0, fnum;
    
    while(1){
        printf("1:search  2:add  3:delete  4:print  5:exit\n");
        scanf("%d", &num);
        
        
        if(num>5 || num<1){
            printf("오류!\nwarning fail:%d \n", ++warn_num);
            if(warn_num==5){
                printf("5 selected\n");
                return;
            }
        }else{
            switch(num){
                case 1: printf("%d selected\n", num);
                    printf("멀 찾을꺼야: "); scanf("%d", &fnum);
                    if(find(fnum)==-1) printf("없어!\n");
                    else printf("%d번째에 있어\n", find(fnum));
                    break;
                case 2: printf("%d selected\n", num);
                        printf("뭘 추가할꺼야: "); scanf("%d", &fnum);
                    if(find(fnum)!=-1) printf("already\n");
                    else{
                        *idx=*idx+1;
                        arr[*idx]=fnum;
                    }break;
                case 3: printf("%d selected\n", num);
                    delete(); break;
                case 4: printf("%d selected\n", num);
                        display(); break;
                case 5: printf("%d selected\n", num); return;
            }
        }
        
    }
    
}


int main(void){
    int i;
    
    for(i=0; i<100; i++) arr[i]=-1;
    
    selec();
}