#include <stdio.h>
#include <string.h>


#define MAX 1000000000


int findFirstDivideNum(int num){
    int i;
    
    for(i=100000000; i > num ; i /= 10);
    
    return i;
}


int checkLuckyNum(int num, int dividenum){
    if(dividenum == 0) return 1;
    
    if(num/dividenum == 4)
        return checkLuckyNum(num - 4*dividenum, dividenum/10);
    else if(num/dividenum == 7)
        return checkLuckyNum(num - 7*dividenum, dividenum/10);
    else return 0;
}


int findLuckyNum(int *A, int *B){
    int i, ret = 0;
    
    for(i = *A; i <= *B; i++)
        ret += checkLuckyNum(i, findFirstDivideNum(i));
    return ret;
}


int numberOk(int *A, int *B){
    int ret = 0;
    
    if(*A > 0 && *A < 1000000000)
        if(*B > 0 && *B < 1000000000)
            if(*A <= *B) ret++;
    return ret;
}


void scanNum(int *A, int *B){
    while(1){
        printf("숫자를 2개 입력하세요(1~1,000,000,000): ");
        scanf("%d%d", A, B);
        
        if(numberOk(A, B)) break;
        else printf("다시 입력하세요. \n");
    }
}


int main(void){
    int A, B;
    int *pA = &A, *pB = &B;
    
    scanNum(pA, pB);
    
    printf("행운의 숫자는 %d개 만큼 있습니다. \n", findLuckyNum(pA, pB));
}
