//
//  sort.h
//  알고리즘 트레이닝 2.2.1 1번 문제 정렬 후 탐색
//
//  Created by 한현민 on 2017. 6. 18..
//  Copyright © 2017년 한현민. All rights reserved.
//

#ifndef sort_h
#define sort_h

#include <stdio.h>

#define DISK_SIZE 1000


struct run{
    int element[DISK_SIZE];
    int curElementIdx;
    long runSize;
    int curReadNum;
};
typedef struct run Run;







void sort(char sourceName[], char printSourceName[], int runNum, int runSize);



#endif /* sort_h */
