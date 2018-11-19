#include <stdio.h>
#include <string.h>

#define STRINGMAX 100
#define TESTMAX 50


int chTOint(char *token){
    int sum = 0, E=1;
    long i;
    
    for(i=strlen(token)-1; i>=0; i--){
        sum += (token[i]-48)*E;
        E *= 10;
    }
    return sum;
}


void stringTOArr(char string[], int ability[]){
    char *token, *delimiter = " ";
    int i = 0;
    
    token = strtok(string, delimiter);
    
    while(token){
        ability[i++] = chTOint(token);
        token = strtok(NULL, delimiter);
    }
}


void scanString(char string[], char colleage[]){
    printf("%s의 선수들의 능력을 입력해주세요. \n", colleage);
    gets(string);
    fflush(stdin);
}


int scanSet(int N){
    while(1){
        printf("세트의 수를 입력하세요: ");
        scanf("%d", &N);
        
        if(N >= 1 && N <= 50) break;
        else printf("다시 입력하세요. \n");
    }
    return N;
}


int scanT(int T){
    while(1){
        printf("테스트의 수를 입력하세요: ");
        scanf("%d", &T);
        
        if(T >= 1 && T <= 50) break;
        else printf("다시 입력하세요.\n");
    }
    return T;
}


int main(int argc, char *argv[]){
    char stringk[STRINGMAX] = {'\0'}, stringp[STRINGMAX] = {'0'};
    int T=0, N=0;
    int abilityk[TESTMAX] = {0}, abilityp[TESTMAX] = {0};
    
    
    T = scanT(T);
    N = scanSet(N);
    scanString(stringk, "KAIST");
    scanString(stringp, "POSTECH");
    
    stringTOArr(stringk, abilityk);
    stringTOArr(stringp, abilityp);
    
    return 0;
}
