#include <stdio.h>
#include <string.h>
#define SIZE 50


void prinResult(char num1[], char num2[], char result[]){
    if(result[0] == '\0') printf("%s + %s = %s\n",num1, num2, result+1);
    else printf("%s + %s = %s\n",num1, num2, result);
}


void cheakResultBigger10(char result[], int idx3){
    if (result[idx3] < 58) return;
    
    
    result[idx3] -= 10;
    result[idx3-1] += 1;
    
    if(idx3==1) result[idx3-1] += 48;
}


int charTolnt(char ch){
    return ch-48;
}


void plusNum1AndNum2(char numstring1[], char numstring2[], char result[],int idx1, int idx2, int idx3){
    if(idx1<0){
        result[idx3] += (charTolnt(numstring2[idx2]) + 48);
    }else if(idx2<0){
        result[idx3] += (charTolnt(numstring1[idx1]) + 48);
    }else{
        result[idx3] += (charTolnt(numstring1[idx1]) + charTolnt(numstring2[idx2]) + 48);
    }
}


void plusString(char numstring1[], char numstring2[], char result[],int idx1, int idx2, int idx3){
    if(idx1 < 0 && idx2 < 0) return;
    
    plusNum1AndNum2(numstring1, numstring2, result, idx1, idx2, idx3);
    cheakResultBigger10(result, idx3);
    
    plusString(numstring1,numstring2, result, idx1-1, idx2-1, idx3-1);
}


void getNum1andNum2(char numstring1[], char numstring2[]){
    printf("Input num1 \n");
    gets(numstring1);
    printf("Input num2 \n");
    gets(numstring2);
}


int main(void){
    char numstring1[SIZE], numstring2[SIZE], result[SIZE+1]={'\0'};
    int idx1, idx2, idx3;
    
    getNum1andNum2(numstring1, numstring2);
    
    idx1 = strlen(numstring1)- 1, idx2 = strlen(numstring2)-1;
    idx3 = idx1>idx2 ? idx1+1 : idx2+1;
    
    plusString(numstring1, numstring2, result, idx1, idx2, idx3);
    prinResult(numstring1, numstring2, result);
    
    return 0;
}
