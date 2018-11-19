#include "header.h"

int stdoutAll(char *fname){
    FILE *f;
    char string[80];
    
    if((f = fopen(fname, "rb")) == NULL){
        printf("File is not open! \n");
        return 1;
    };
    
    while(!feof(f)){
        strcpy(string,"\0");
        fgets(string, 80, f);
        fprintf(stdout, "%s", string);
    }
    
    
    fclose(f);
    return 0;
}


void prinOne(fstudent fs){
    fprintf(stdout, "%d %s %d %d %d \n", fs->num, fs->name, fs->mid, fs->finals, fs->quiz);
}


fstudent scanOneStudent(FILE *f){
    fstudent fs;
    fs = (fstudent) malloc(sizeof(student));
    
    fscanf(f, "%d %s %d %d %d", &fs->num, fs->name, &fs->mid, &fs->finals, &fs->quiz);
    return fs;
}

int returnidx(char *string, char *buf){
    if(strcmp(buf, "ㅏ")<0){
        return 4;
    }else
        return 2;
}

int searchWithInitialName(FILE *f){
    char name[10];
    fstudent fstudent;
    int cnt = 0;
    char buf[3];
    int idx[3] = {0};
    buf[2] = '\0';
    int i;
    
    
    
    printf("초성을 입력하세요. \n");
    fgets(name, 5, stdin);
    name[ strlen(name)-1 ] = '\0';
    
    while(!feof(f)){
        fstudent = scanOneStudent(f);
        
        for(i=0; i<3; i++){
            idx[i]
        }
    }
}

int searchWithName(FILE *f){
    char name[30];
    fstudent fstudent;
    int cnt = 0;
    
    printf("이름을 입력하세요. \n");
    fgets(name, 30, stdin);
    name[ strlen(name)-1 ] = '\0';
    
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
        printf("초성으로 탐색하려면 '초성'을 입력하세요. \n");
        fflush(stdin);
        fgets(string, 10, stdin);
        
        if(!strcmp(string, "번호\n")){
            searchWithNum(f);
            fclose(f);
            return 0;
        }else if(!strcmp(string, "이름\n")){
            searchWithName(f);
            fclose(f);
            return 0;
        }else if(!strcmp(string, "초성\n")){
            
            fclose(f);
            return 0;
        }else
            printf("다시 입력하세요. \n");
    }
    
    fclose(f);
    return 1;
}
