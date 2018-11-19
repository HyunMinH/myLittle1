#include "header.h"

int main(int argc, char *argv[]){
    char option;
    FILE *f;
    char fname[30] = "basic.bin";
    
    while(1){
        printf("전체보기(t), 탐색(s), 범위탐색(q), 삽입(i), 수정(u), 성적처리(g), 종료(f):");
        scanf(" %c", &option);
        
        if(option == 'f') break;
        
        switch(option){
            case 't': stdoutAll(f, fname); break;
            case 's': searchOne(f,fname); break;
            //case 'q':
            case 'i': insert(f, fname); break;
            case 'u': modify(f, fname); break;
            //case 'g':
            default: printf("잘못 입력하였습니다. \n"); break;
        }
    }
    
    return 0;
}
