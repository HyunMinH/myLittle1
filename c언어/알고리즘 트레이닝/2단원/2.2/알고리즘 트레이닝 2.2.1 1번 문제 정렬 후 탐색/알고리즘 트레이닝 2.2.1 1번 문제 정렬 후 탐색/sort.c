#include "sort.h"
#include <stdio.h>


#define FALSE_DATA -1
#define TRUE 1
#define FALSE 0




void initRun(Run run[], int runNum, int runSize);

void fillTree(int tree[], Run run[], int runNum);

long findLastWinner(long tree[], int treeNum);

void printWinner(char printSourceName[], int winner);

void fillRuns(char sourceName[], Run run[], int runNum, int runSize);

int sortFinish(Run run[], int runNum, long runSize);

void runUpdate(char sourceName[], int winner, Run run[], int runNum, int runSize);

void fileInit(char sourceName[]);


void sort(char sourceName[], char printSourceName[], int runNum, int runSize){
    Run run[32];
    long tree[16], lastWinner, treeNum = runNum;
    
    initRun(run, runNum, runSize);
    
    fillRuns(sourceName, run, runNum, runSize);
    
    while(sortFinish(run, runNum, runSize) == FALSE){
        fillTree(tree, run, runNum);
        
        lastWinner = findLastWinner(tree, treeNum);
        
        printWinner(printSourceName, lastWinner);
        
        runUpdate(sourceName, lastWinner, run, runNum, runSize);
    }
}



void runUpdate(char sourceName[], long winner, Run run[], long runNum, long runSize){
    Run* findRunPtr;
    int i;
    
    for(i=0; i<runNum; i++){
        if(run[i].element[run[i].curElementIdx] == winner){
            findRunPtr = &run[i];
            break;
        }
    }
    
    findRunPtr->curElementIdx += 1;
    
    if(findRunPtr->curElementIdx >= DISK_SIZE){
        fillRuns(sourceName, run, runNum, runSize);
        
        findRunPtr->curElementIdx = 0;
    }
}



void initRun(Run run[], int runNum, int runSize){
    int i;
    
    for(i=0; i<runNum; i++){
        (&run[i])->curElementIdx = 0;
        (&run[i])->runSize = runSize;
        (&run[i])->curReadNum = 0;
        (&run[i])->element[0] = FALSE_DATA;
    }
}



void fillTree(long tree[], Run run[], int runNum){
    long start = runNum/2, last = runNum-1, i, runIdx = 0;
    Run curRun;
    
    for(i = start; i <= last; i++){
        curRun = run[runIdx++];
        tree[i] = curRun.element[curRun.curElementIdx];
    }
}



long findWinner(long n1, long n2){
    if(n1 == FALSE_DATA)
        return n2;
    
    if(n2 == FALSE_DATA)
        return n1;
    
    
    if(n1 < n2)
        return n1;
    else
        return n2;
}



long findLastWinner(long tree[], long treeNum){
    long i, parentIdx, winner;
    
    for(i = treeNum; i >= 2; i = i-2){
        parentIdx = i / 2;
        
        winner = findWinner(i, i+1);
        
        tree[parentIdx] = winner;
    }
    
    return tree[1];
}



void printWinner(char printSourceName[], int winner){
    FILE* fp;
    
    fp = fopen(printSourceName, "a");
    
    if(fp == NULL){
        printf("file is not open\n");
        return;
    }
    
    fprintf(fp, "%d ", winner);
    
    fclose(fp);
}




int sortFinish(Run run[], int runNum, long runSize){
    int i;
    
    for(i=0; i<runNum; i++){
        if(run[i].curReadNum * DISK_SIZE < runSize)
            return FALSE;
    }
    
    
    return TRUE;
}





void fillOneRun(char sourceName[], Run* run, long runStart, long runLast){
    FILE* fp;
    long i, ridx, diskStart = runStart + (run->curReadNum * DISK_SIZE);
    long diskLast = diskStart + DISK_SIZE-1;
    
    
    fp = fopen(sourceName, "r");
    if(fp == NULL){
        printf("파일이 열리지 않았습니다.\n");
        return;
    }
    
    
    for(i = diskStart, ridx = 0; i<= diskLast; i++, ridx++){
        if(i > runLast)
            run->element[ridx] = FALSE_DATA;
        else
            fscanf(fp, "%d", &run->element[ridx]);
    }
    
    
    fclose(fp);
}



void fillRuns(char sourceName[], Run run[], int runNum, int runSize){
    long runStart, i, runLast;
    
   
    for(i=0; i<runNum; i++){
        if(run[i].curElementIdx >= DISK_SIZE || run[i].element[run[i].curElementIdx] == FALSE_DATA){
            runStart = runSize * i;
            runLast = runSize * (i+1) - 1;
            
            fillOneRun(sourceName, &run[i], runStart, runLast);
        }
    }
}




void fileInit(char sourceName[]){
    FILE* fp;
    
    fp = fopen(sourceName, "w");
    
    if(fp == NULL){
        printf("file is not open\n");
        return;
    }
    
    fclose(fp);
}
