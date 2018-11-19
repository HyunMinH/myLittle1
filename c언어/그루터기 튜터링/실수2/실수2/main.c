//https://www.acmicpc.net/problem/8958
#include <stdio.h>



int main(void) {
    char string[11];
    int result = 0, curQuizScore = 0, strLength, i;
    
    printf("string의 길이를 입력하세요: ");
    scanf("%d", &strLength);
    
    printf("string을 입력하세요(ex)OOXXOXXOOO): ");
    scanf("%s", string);	//문자열은 scanf에 이름만 넣어야 합니다.
				//문자열 배열도 scanf에 이름만 넣어야 합니다.
    
    for (i = 0; i < strLength; i++) {
        if (string[i] == 'O') {
            curQuizScore = curQuizScore + 1;
            result = result + curQuizScore;
        }
        else if (string[i] == 'X') {
            curQuizScore = 0;
        }
    }
    
    printf("최종점수는 %d입니다. \n", result);
}

