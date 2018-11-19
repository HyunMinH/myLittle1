//
//  main.c
//  AlgoTest
//
//  Created by 한현민 on 2018. 4. 2..
//  Copyright © 2018년 한현민. All rights reserved.
//



#include <stdio.h>

#define MAX_NUM 100000


int min(int n1, int n2){
    if(n1 > n2) return n2;
    else return n1;
}


void printComb(int p[], int n){
    int i;
    
    i = n;
    while(i > 0){
        printf("%d ", i-p[i]);
        i = p[i];
    }
}


void initArray(int ary[], int n, int init_num){
    int i;
    for(i=0; i<=n; i++)
        ary[i] = init_num;
}

int Coin2(int n){
    int i;
    int N[MAX_NUM] = {0}, P[MAX_NUM] = {0};
    
    initArray(N, n, 987654321);
    
    N[0] = 0;
    for(i=1; i<=n; i++){
        if(i-1 >= 0 && N[i] > N[i-1]){
            N[i] = N[i-1] + 1;
            P[i] = i-1;
        }
        if(i-2 >= 0 && N[i] > N[i-2]){
            N[i] = min(N[i], N[i-2] + 1);
            P[i] = i-2;
        }
        if(i-6 >= 0 && N[i] > N[i-6]){
            N[i] = min(N[i], N[i-6] + 1);
            P[i] = i-6;
        }
        if(i-8 >= 0 && N[i] > N[i-8]){
            N[i] = min(N[i], N[i-8] + 1);
            P[i] = i-8;
        }
    }
    
    printComb(P, n);
    return N[n];
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int n, k;
    
    scanf("%d", &n);
    
    printf("%d\n", Coin2(n));
    return 0;
}
