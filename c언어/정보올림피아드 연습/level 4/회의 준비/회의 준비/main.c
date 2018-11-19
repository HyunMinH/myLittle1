#include "team.h"



void scanRelation(struct man man1[], int M, int N){
    int i, A, B;
    
    for(i=1; i<=M; i++){
        scanf("%d", &A);
        scanf("%d", &B);
        
        if(A >= 1 && A <= N){
            if(B >= 1 && B <= N){
                man1[A].liked[ man1[A].likedmax++ ] = B;
            }
        }else{
            printf("다시 입력하세요. \n");
            i--;
        }
    }
}



int scanNumOFRealation(){
    int num;
    
    while(1){
        printf("관계의 수를 입력하세요(1~100): ");
        scanf("%d", &num);
        
        if(num >= 1 && num <= 100) break;
        else printf("다시 입력하세요. \n");
    }
    return num;
}



int scanManNum(){
    int num;
    
    while(1){
        printf("사람의 수를 입력하세요(1~100): ");
        scanf("%d", &num);
        
        if(num >= 1 && num <= MAX) break;
        else printf("다시 입력하세요. \n");
    }
    return num;
}



int main(void){
    struct man man1[MAX] = {{0}, {0}, {0}};
    int team[20][MAX] = {0};
    int N, M;
    
    
    N = scanManNum();
    M = scanNumOFRealation();
    
    
    scanRelation(man1, M, N);
    
    printf("Hello world!");
}
