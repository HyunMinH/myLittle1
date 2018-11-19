#include <stdio.h>
#include <string.h>

#define CASEMAX 100
#define STRINGMAX 10000

int checkInto(char string[][STRINGMAX], int idxcase, int idxch){
    int ret = 0;
    
    if(string[idxcase][idxch] == '{') ret++;
    else if(string[idxcase][idxch] == '[') ret++;
    else if(string[idxcase][idxch] == '(') ret++;
    
    return ret;
}


int checkMatch(char string[][STRINGMAX], int idxcase, int idxch1, int idxch2){
    int ret = 0;
    
    if(string[idxcase][idxch1] == '{'){
        if(string[idxcase][idxch2] == '}')
            ret++;
    }else if(string[idxcase][idxch1] == '['){
        if(string[idxcase][idxch2] == ']')
            ret++;
    }else if(string[idxcase][idxch1] == '('){
        if(string[idxcase][idxch2] == ')')
            ret++;
    }
    return ret;
}



char checkOneSet(char string[][STRINGMAX], int idxcase, int *idxch){
    int hereidx = *idxch;
    char ret = '\0';
    
    if(strlen(string[idxcase]) == 1) return 'n';
    
    if(*idxch >= strlen(string[idxcase]) ) return 'y';
    
    while(1){
        if(checkInto(string, idxcase, *idxch+1)){
            *idxch += 1;
            return ret = checkOneSet(string, idxcase, idxch);
        }else break;
    }
    
    *idxch += 1;
    if(!checkMatch(string, idxcase, hereidx, *idxch)) return 'n';
    else{
        if(hereidx == 0 && *idxch != strlen(string[idxcase]) - 1){
            *idxch += 1;
            ret = checkOneSet(string, idxcase, idxch);
        }else return 'y';
    }

    return ret;
}


void prinMatchOrNo(int c, char string[][STRINGMAX], int idxcase){
    int buffer = 0;
    
    if(checkOneSet(string, idxcase, &buffer) == 'y'){
        printf("YES \n");
    }else printf("NO \n");
}


void checkAllSet(int c, char string[][STRINGMAX]){
    int i;
    
    for(i=0; i < c; i++)
        prinMatchOrNo(c, string, i);
}


void scanString(int c, char string[][STRINGMAX]){
    int i;
    
    for(i = 0; i < c; i++){
        printf("%d번째 괄호 문자열을 입력하세요.(최대 길이는 10000입니다.) \n", i+1);
        scanf("%s", string[i]);
    }
}


int scanCase(int c){
    while(1){
        printf("케이스 수를 입력하세요(1~100): ");
        scanf("%d", &c);
        
        if(c > 0 && c <= 100) break;
        else printf("다시 입력하세요. \n");
    }
    return c;
}


int main(void){
    char string[CASEMAX][STRINGMAX] = {0};
    int c;
    
    c=scanCase(c);
    scanString(c, string);
    
    checkAllSet(c, string);
    
    return 0;
}
