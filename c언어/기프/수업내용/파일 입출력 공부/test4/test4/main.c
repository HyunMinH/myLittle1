#include <stdio.h>
#include <string.h>


int main(void){
    char string[100];
    
    printf("Hello World! \n");
    fgets(string, sizeof(string), stdin);
    
    printf("%s", string);
}
