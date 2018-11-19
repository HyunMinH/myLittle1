//
//  main.c
//  성적 처리 문제
//
//  Created by 한현민 on 2016. 9. 30..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>

typedef struct student{
    char name[20];
    int math;
    int eng;
    int kor;
} student;



void switc (int vc[]){
    int i, j, box;
    
    for(i=0; i<3; i++)
        for(j=i+1; j<3; j++)
            if (vc[i]>vc[j]){
                box=vc[i];
                vc[i]=vc[j];
                vc[j]=box;
            }

}

void prin(int math[], int eng[], int kor[], student A[], int num){
    int i, asdf=0;
    
    printf(" %s:", A[num].name);
    
    
    for(i=0; i<3; i++)
        if(math[i]==A[num].kor) asdf = i;
    
    printf("%d", A[num].kor);
    switch(asdf){
        case 2: printf("(A)  "); break;
        case 1: printf("(B)  "); break;
        case 0: printf("(C)  "); break;
    }
    
    
    for(i=0; i<3; i++)
        if(math[i]==A[num].eng) asdf = i;
    
    printf("%d", A[num].eng);
    switch(asdf){
        case 2: printf("(A)  "); break;
        case 1: printf("(B)  "); break;
        case 0: printf("(C)  "); break;
    }
    
    
    for(i=0; i<3; i++)
        if(math[i]==A[num].math) asdf = i;
    
    printf("%d", A[num].math);
    switch(asdf){
        case 2: printf("(A)  "); break;
        case 1: printf("(B)  "); break;
        case 0: printf("(C)  "); break;
    }
    
    
}

int main(void){
    student A[3];
    int i;
    int math[3]={A[0].math, A[1].math, A[2].math};ㅁ
    int kor[3]={A[0].kor, A[1].kor, A[2].kor};
    int eng[3]={A[0].eng, A[1].eng, A[2].eng};
    
    for(i=0; i<3; i++){
        printf("이름과 국어, 영어, 수학 성적을 입력하시오: ");
        scanf("%s%d%d%d", A[i].name, &A[i].kor, &A[i].eng, &A[i].math);
        fflush(stdin);
    }
    
    switc(math);
    switc(kor);
    switc(eng);
    prin(math, eng, kor, A, 0);
    prin(math, eng, kor, A, 1);
    prin(math, eng, kor, A, 2);
    
}