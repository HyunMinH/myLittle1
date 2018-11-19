//
//  main.c
//  알고리즘 트레이닝 2.2.1 1번 문제 정렬 후 탐색
//
//  Created by 한현민 on 2017. 6. 18..
//  Copyright © 2017년 한현민. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define DATA_NUM 100000


void makeSourceFile(char* sourceName);


int main(int argc, const char * argv[]) {
    // insert code here...
    int runSize = DATA_NUM/50;
    
    
    makeSourceFile("source.txt");
    
    sort("source.txt", "sort1.txt", 4, runSize);
    
    runSize = runSize*4;
    sort("sort1.txt", "sort2.txt", 4, runSize);
    
    runSize = runSize*4;
    sort("sort2.txt", "sort3.txt", 4, runSize);

    runSize = DATA_NUM;
    sort("sort3.txt", "sort4.txt", 4, runSize);

    
    
    
    
    printf("Hello, World!\n");
    return 0;
}


void makeSourceFile(char* sourceName){
    long i, num;
    FILE* fp;
    
    fp = fopen(sourceName, "w");
    
    if(fp == NULL){
        printf("file is not open\n");
        return;
    }
    
    for(i=0; i<100000; i++){
        num = (long)rand()<<15 | rand();
        fprintf(fp, "%ld ", num);
    }
    
    fclose(fp);
}
