#include "header.h"

fstudent createNode(FILE *f){
    fstudent fs;
    
    fs = (fstudent) malloc(sizeof(student));
    
    if(!fs){
        printf("노드 생성을 위한 메모리 할당에 문제가 있습니다. \n");
        return NULL;
    }
    
    fscanf(f, "%d %s %d %d %d", &fs->num, fs->name, &fs->mid, &fs->finals, &fs->quiz);
    
    return fs;
}


fstudent append(fstudent head, fstudent cur){
    fstudent nextnode = head;
    
    if(head == NULL){
        head = cur;
        return head;
    }
    
    while(nextnode->next){
        nextnode = nextnode->next;
    }
    
    nextnode->next = cur;
    return head;
}


fstudent fillfs(FILE *f, fstudent fs[]){
    int i = 0;
    fstudent head = NULL;
    
    while(!feof(f)){
        fs[i] = createNode(f);
        i++;
    }
    
    i = 0;
    while(!fs[i]->num){
        head = append(head, fs[i]);
        i++;
    }
    
    return head;
}


fstudent modifyStruct(FILE *f, fstudent *fs){
    int num, idx;
    
    printf("수정할 정보의 번호를 입력하세요: ");
    scanf("%d", &num);
    
    idx = num-1;
    
    printf("%d의 정보: (%s,%d,%d,%d) \n", num, fs[idx]->name, fs[idx]->mid, fs[idx]->finals, fs[idx]->quiz);
    
    printf("수정할 내용:");
    scanf("%s %d %d %d", fs[idx]->name, &fs[idx]->mid, &fs[idx]->finals, &fs[idx]->quiz);
    
    return fs[0];
}


int saveModified(FILE *f, fstudent fs[]){
    int i = 0;
    
    rewind(f);
    
    while(!fs[i]->num){
        fprintf(f, "%d %s %d %d %d\n", fs[i]->num, fs[i]->name, fs[i]->mid, fs[i]->finals, fs[i]->quiz);
        i++;
    }
    
    return 1;
}


int modify(FILE *f, char fname[]){
    fstudent fs[20] = {0};
    fstudent head = NULL;
    
    if((f = fopen(fname, "rb+")) == NULL){
        printf("File is not open! \n");
        return 1;
    }
    
    head = fillfs(f, fs);
    head = modifyStruct(f, fs);
    saveModified(f, fs);
    
    fclose(f);
    return 0;
}


int insert(FILE *f, char *fname){
    char string[80] = {'\0'};
    fstudent fs;
    
    if((f = fopen(fname, "wb")) == NULL){
        printf("File is not open! \n");
        return 1;
    };
    
    fflush(stdin);
    
    printf("추가할 정보: ");
    fgets(string, sizeof(string), stdin);
    
    while(!feof(stdin)){
        sscanf(string, "%d %s %d %d %d", &fs->num, fs->name, &fs->mid, &fs->finals, &fs->quiz);
        fs->num += 1;
        
        fprintf(f, "%d %s %d %d %d\n", fs->num, fs->name, fs->mid, fs->finals, fs->quiz);
        
        printf("추가할 정보: ");
        fgets(string, sizeof(string), stdin);
    }
    
    fclose(f);
    return 0;
}


fstudent deleteStruct(fstudent fs[], fstudent head){
    int num, idx;
    
    printf("삭제할 정보의 번호를 입력하세요. \n");
    scanf("%d", &num);
    
    idx = num-1;
    
    fs[idx-1]->next = fs[idx+1];
    
    return head;
}


int deleteOne(FILE *f, char fname[]){
    fstudent fs[20] = {0};
    fstudent head = NULL;
    
    if((f = fopen(fname, "rb+")) == NULL){
        printf("File is not open! \n");
        return 1;
    }
    
    head = fillfs(f, fs);
    head = deleteStruct(fs, head);
    saveModified(f, fs);
    
    fclose(f);
    return 0;
}
