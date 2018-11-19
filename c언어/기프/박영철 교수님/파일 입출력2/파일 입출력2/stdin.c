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
    int count;
    fstudent head = NULL;
    
    while(!feof(f)){
        fs[i] = createNode(f);
        i++;
    }
    count = i;

    for(i=0; i<count; i++)
        head = append(head, fs[i]);

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


int modify(char fname[]){
    FILE *f;
    fstudent fs[20];
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


int insert(char *fname, int lastnum){
    FILE *f;
    char string[80] = {'\0'};
    fstudent fs = (struct student*) malloc(sizeof(student));
    
    if((f = fopen(fname, "ab")) == NULL){
        printf("File is not open! \n");
        return 1;
    };
    
    printf("추가할 정보: ");
    fgets(string, sizeof(string), stdin);
    
    while(strcmp(string, "quit\n")){
        sscanf(string, "%s %d %d %d", fs->name, &fs->mid, &fs->finals, &fs->quiz);
        fs->num = lastnum++;
        
        fprintf(f, "%d %s %d %d %d\n", fs->num, fs->name, fs->mid, fs->finals, fs->quiz);
        
        printf("추가할 정보: ");
        fgets(string, sizeof(string), stdin);
    }
    
    fclose(f);
    return fs->num;
}

int lastnum(fstudent fs[]){
    fstudent nextnode = fs[0];
    while(nextnode->next){
        nextnode = nextnode->next;
    }
    return nextnode->num;
}
fstudent modNum(fstudent fs[], fstudent cur){
    fstudent nextnode = cur;
    while(nextnode->num){
        nextnode->num--;
        nextnode = nextnode->next;
    }
    return fs[0];
}


fstudent deleteStruct(fstudent fs[], fstudent head){
    int num, idx;
    
    printf("삭제할 정보의 번호를 입력하세요. \n");
    scanf("%d", &num);
    
    idx = num-1;
    
    fs[idx-1]->next = fs[idx+1];
    head = modNum(fs, fs[idx+1]);
    
    return head;
}


int deleteOne(char fname[]){
    FILE *f;
    fstudent fs[20] = {0};
    fstudent head = NULL;
    
    if((f = fopen(fname, "rb+")) == NULL){
        printf("File is not open! \n");
        return 1;
    };
    
    head = fillfs(f, fs);
    head = deleteStruct(fs, head);
    saveModified(f, fs);
    
    fclose(f);
    return lastnum(fs);
}

int scanLastNum(char *fname){
    fstudent fs[20];
    FILE *f;
    if((f = fopen(fname, "rb+")) == NULL){
        printf("File is not open! \n");
        return 1;
    };
    fs[0] = fillfs(f, fs);
    fclose(f);
    if(!fs[0]->num)
        return 0;
    else
        return lastnum(fs);
}
