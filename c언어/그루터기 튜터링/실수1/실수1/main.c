//https://www.acmicpc.net/problem/8393

#include <stdio.h>


int main(void) {
    int sum, i, max;
    
    printf("1부터 어떤 숫자까지의 총합\n");
    printf("숫자를 입력하세요: ");
    scanf("%d", &max);
    
    for (i = 1; i <= max; i++) {
        sum = sum + i;
    }
    
    printf("sum = %d\n", sum);
}
