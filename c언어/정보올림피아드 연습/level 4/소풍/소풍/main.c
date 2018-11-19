#include <stdio.h>


#define COWMAX 100
#define FARMMAX 1000


int path[FARMMAX][FARMMAX] = {0};
int farmexistcow[COWMAX] = {0};



void scanPath(int pathnum){
    int i, A, B;
    
    for(i=0; i<pathnum; i++){
        scanf("%d", &A);
        scanf("%d", &B);
        path[A-1][B-1] = 1;
    }
}




int checkAtoB(int farmincow[], int cownum, int farmnum, int A, int B){
    int ret = 0, i;
    
    if(farmincow[A] == 0 || farmincow[B] == 0)
        return 0;
    
    if(A == B)
        return 1;
    
    for(i = 0; i < farmnum; i++){
        if(path[A][i]){
            ret += checkAtoB(farmincow, cownum, farmnum, i, B);
        }
    }
    return ret;
}



int findTogether(int farmnum, int cownum, int farmincow[]){
    int ret = 0, desti, start, buffer = 0;
    
    for(desti = 0; desti < farmnum; desti++){
        buffer = 0;
        
        for(start = 0; start < farmnum; start++){
            if(checkAtoB(farmincow, cownum, farmnum, start, desti) != 0){
                buffer++;
            }
        }
        
        if(buffer >= cownum-1)
            ret++;
    }
    return ret;
}



int main(void){
    int cownum = 2, farmnum = 4, pathnum = 4;
    int farmincow[COWMAX] = {0,1,1};
    
    scanPath(pathnum);
    
    printf("%d\n", findTogether(farmnum, cownum, farmincow) );
    return 0;
}
