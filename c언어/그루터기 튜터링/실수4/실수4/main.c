//https://www.acmicpc.net/problem/10809
#include <stdio.h>


int main(void) {
    char string[20];
    int index = 0;
    char want;
    
    printf("문자열을 입력하세요: ");
    scanf("%s", string);
    
    printf("찾을 문자를 입력하세요: ");
    scanf(" %c", &want);
    
    while (string[index] != want) {
        index = index + 1;
    }
    
    printf("%c는 문자열의 %d번째에 있습니다. \n", want, index+1);
}
