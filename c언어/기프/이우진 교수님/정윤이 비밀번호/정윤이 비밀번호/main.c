#include <stdio.h>
#include <conio.h>
#include <string.h>

#define NUM 100

int InputCheck(char arr[]){
    int i;
    
    //입력
    for(i = 0; i < NUM; i++){
        arr[i] = getch();
        
        if(arr[i] == '\r'){
            printf("\n");
            arr[i] = '\0';
            break;
        }
        printf("*");
    }
    
    //글자수체크
    if(strlen(arr) < 5 || strlen(arr) >= 10){
        printf("Retry\n");
        
        return 1;
    }
    return 0;
}

int Compare(char arr1[], char arr2[]){
    if(strcmp(arr1,arr2) == 0){
        return 1;
    }
    
    else{
        printf("Retry\n");
        return 0;
    }
}

void Reset(char arr[]){
    int i;
    for(i = 0; i <NUM; i++){
        arr[i] = '\0';
    }
}


void main(){
    
    char arr1[NUM] = {'\0'};
    char arr2[NUM] = {'\0'};
    
    while(1){
        
        if(InputCheck(arr1) == 1){
            Reset(arr1);
            continue;
        }
        
        if(InputCheck(arr2) == 1){
            Reset(arr1);
            Reset(arr2);
            continue;
        }
        
        if (Compare(arr1, arr2) == 1){
            break;
        }
        
        Reset(arr1);
        Reset(arr2);
        
    }
}
