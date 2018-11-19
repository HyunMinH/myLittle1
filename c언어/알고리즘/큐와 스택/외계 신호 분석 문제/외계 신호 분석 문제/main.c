#include <stdio.h>

#define CASEMAX 20
#define SUMANDLENGHTMAX 5000000


void getSignal(int signal[][SUMANDLENGHTMAX], int lenght[], int C){
    int i, j;
    
    for(i=0; i < C; i++){
        signal[i][0] = 1983;
        for(j=1; j < lenght[i]; j++)
            signal[i][j] = (signal[i][j-1] % 10000)+1;
    }
}


int scanCase(int C){
    while(1){
        printf("케이스의 수를 입력하세요: ");
        scanf("%d", &C);
        
        if(C > 0 && C <= CASEMAX) break;
        else printf("다시 입력하세요. \n");
    }
    return C;
}


void scanSumORLenght(int sumorlenght[], int C){
    int i;
    
    for(i=0; i < C; i++){
        while(1){
            printf("숫자를 입력하세요: ");
            scanf("%d", &sumorlenght[i]);
            
            if(sumorlenght[i] > 0 && sumorlenght[i] <= 5000000) break;
            else printf("다시 입력하세요. \n");
        }
    }
}


int main(void){
    int C;
    int sum[CASEMAX], lenght[CASEMAX];
    int signal[CASEMAX][SUMANDLENGHTMAX];
    
    C = scanCase(C);
    scanSumORLenght(sum, C);
    scanSumORLenght(lenght, C);
    
    getSignal(signal, lenght, C);
    
    return 0;
}
