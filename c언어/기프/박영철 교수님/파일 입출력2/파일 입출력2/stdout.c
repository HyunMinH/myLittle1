#include "header.h"

int stdoutAll(char *fname){
    FILE *f;
    char string[80];
    
    if((f = fopen(fname, "rb")) == NULL){
        printf("File is not open! \n");
        return 1;
    }
    
    while(feof(f)){
        fgets(string, 80, f);
        fprintf(stdout, "%s", string);
    }
    
    fclose(f);
    return 0;
}


void prinOne(fstudent fs){
    fprintf(stdout, "%2d %18s %3d %3d %3d", fs->num, fs->name, fs->mid, fs->finals, fs->quiz);
}


fstudent scanOneStudent(FILE *f){
    fstudent fs = {0};
    
    fscanf(f, "%d %s %d %d %d", &fs->num, fs->name, &fs->mid, &fs->finals, &fs->quiz);
    return fs;
}


int searchWithName(FILE *f){
    char name[30];
    fstudent fstudent;
    int cnt = 0;
    
    printf("이름을 입력하세요. \n");
    fgets(name, 30, stdin);
    
    while(!feof(f)){
        fstudent = scanOneStudent(f);
        
        if(!strcmp( fstudent->name, name )){
            prinOne(fstudent);
            cnt++;
        }
    }
    
    if(!cnt)
        printf("찾으시는 학생이 없습니다. \n");
    return 0;
}

int searchWithNum(FILE *f){
    int num, cnt = 0;
    fstudent fstudent;
    
    printf("번호를 입력하세요. \n");
    scanf("%d", &num);
    
    while(!feof(f)){
        fstudent = scanOneStudent(f);
        
        if(fstudent->num == num){
            prinOne(fstudent);
            cnt++;
        }
    }
    
    if(!cnt)
        printf("찾으시는 학생이 없습니다. \n");
    return 0;
}


int searchOne(char *fname){
    FILE *f;
    char string[10];
    
    if((f = fopen(fname, "rb")) == NULL){
        printf("File is not open! \n");
        return 1;
    }
    
    while(1){
        printf("번호로 탐색하려면 '번호'를 입력하시고 ");
        printf("이름으로 탐색하려면 '이름'을 입력하세요. \n");
        fgets(string, 10, stdin);
        
        if(!strcmp(string, "번호\n")){
            searchWithNum(f);
            fclose(f);
            return 0;
        }else if(!strcmp(string, "이름\n")){
            searchWithName(f);
            fclose(f);
            return 0;
        }else
            printf("다시 입력하세요. \n");
    }
    
    fclose(f);
    return 1;
}
