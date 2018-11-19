//
//  main.c
//  제곱수의 합
//
//  Created by 한현민 on 2016. 10. 6..
//
//

#include <stdio.h>
#define D(x) ((x)*(x))



void calc(int num){
    int i, index=0;
    
    for(i=num; i>=1; ){
        if(D(i)<=num){
            index++;
            num -= D(i);
        }else{
            i--;
        }
        if(num==0) break;
    }
    printf("%d\n", index);
}



int main(void){
    int num;
    
    printf("숫자를 하나 입력하세요. \n");
    scanf("%d", &num);
    
    calc(num);
    
    return 0;
    
}