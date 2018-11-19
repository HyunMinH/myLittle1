#include <stdio.h>
#include <string.h>

int main(void){
    char a[3] = "ㄱ";
    char b[3] = "ㅏ";
    
    
    printf("%d", strcmp(a, b));
}
