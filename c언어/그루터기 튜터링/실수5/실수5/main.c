//https://www.acmicpc.net/problem/2577
#include <stdio.h>


int main(void) {
    int num[10];
    int a, b, c, index, divnum, i, result;
    
    printf("곱할 세수를 입력하세요: ");
    scanf("%d %d %d", &a, &b, &c);
    
    
    divnum = 10;
    index = 0;
    
    while (result >= divnum) {
        num[index] = (result % divnum);
        index = index + 1;
        divnum = divnum * 10;
    }
    
    for (i = index-1; i >= 0; i--)
        printf("%d", num[i]);
}

