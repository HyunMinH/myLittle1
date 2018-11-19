#include <stdio.h>
#include <string.h>



void add(double *result, double x, double y){
    *result = x+y;
}

int main(void){
    char str[30] = "yeoifsdhfih iuhdsfh uihf eq";
    char *delimeter = " ,!?";
    char *ptoken;
    
    ptoken = strtok(str, delimeter);
    while(ptoken){
        
        ptoken = strtok(NULL, delimeter);
    }
    
    
}
