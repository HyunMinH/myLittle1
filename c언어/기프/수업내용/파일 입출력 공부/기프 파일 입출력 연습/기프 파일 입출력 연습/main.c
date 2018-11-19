#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
    FILE *f;
    char fname[] = "sample.txt";
    char ch;
    char string[100];
    
    
    if((f = fopen(fname,"w+")) == NULL){
        printf("파일이 열리지 않습니다. \n");
        exit(1);
    };
    
    while(1){
        fgets(string, sizeof(string), stdin);
        
        if(!strcmp(string, "quit\n")) break;
        
        fprintf(f, "%s", string);
        //strcpy(string, "\0");
    }
    
    fprintf(f, "%c", '\0'); // enter
    //이거 비주얼에도 이렇게 되는지 확인하기
    
    fseek(f, 0, SEEK_SET);
    
    
    printf("%ld \n", ftell(f));
    
    while(!feof(f)){
        //printf("%ld \n", ftell(f));
        fscanf(f, "%c", &ch);
        printf("%c", ch);
    }
    
    fclose(f);
    
    return 0;
}
