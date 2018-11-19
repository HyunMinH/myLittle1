#include <stdio.h>


void sumFunction(int sum, int num1, int num2) {
    sum = num1 + num2;
}


void multFunction(int mul, int num1, int num2) {
    mul = num1 * num2;
}


int main(void) {
    int reslut, sum = 0, mult = 1;
    int a, b, c;
    
    printf("세 수를 입력하세요: ");
    scanf("%d %d %d", &a, &b, &c);
    
    sumFunction(sum, a, b);
    printf("a와 b를 더한 값은 %d입니다.\n", sum);
    
    multFunction(mult, a, b);
    printf("a와 b를 곱한 값은 %d입니다.\n", mult);
    
    
    sumFunction(sum, a, c);
    printf("a와 c를 더한 값은 %d입니다.\n", sum);
    
    multFunction(mult, a, c);
    printf("a와 c를 곱한 값은 %d입니다.\n", mult);
    
}

