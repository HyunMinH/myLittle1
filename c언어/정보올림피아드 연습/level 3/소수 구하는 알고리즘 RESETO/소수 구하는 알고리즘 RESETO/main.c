//
//  main.c
//  소수 구하는 알고리즘 RESETO
//
//  Created by 한현민 on 2016. 10. 10..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>

int arr[1000], order[1000], a=0;
int *idx=&a;


void find_erase(int num, int N){
    int i, id=num+1;//여기서 id는 next넘버
    
    if(num==N) return;
    for(i=num+1; i<=N; i++){
        //i=num+1 에서 i가 리얼 순서를 나타내는 수
        if(arr[i-1]!=0){
            if(i%(num+1)==0){
                arr[i-1]=0;
                order[*idx]=i;
                *idx= *idx+1;
            }
        }
    }
    
    while(1){
        if(arr[id]==0) id++;
        else break;
    }
    find_erase(id,N);
    
}


int main(void){
    int N, K, i; //N은 최대 수, K는 몇번째로 지워지는지
    
    
    while(1){
        printf("최대 수를 입력하세요(2~1000): ");
        scanf("%d", &N);
        if(N>=2 && N<=1000) break;
        else printf("다시 입력하세요. \n");
    }
    while(1){
        printf("K번째로 지워지는 K를 입력하시오(2~1000): ");
        scanf("%d", &K);
        if(K>=2 && K<1000) break;
        else printf("다시 입력하세요. \n");
    }
    
    for(i=0; i<N+1; i++) arr[i]=-1;
    
    find_erase(1, N); // 1은 사실 2 배열때문에
    
    printf("K번째로 지워지는 수는 %d입니다. \n", order[K-1]);
    
    return 0;
}