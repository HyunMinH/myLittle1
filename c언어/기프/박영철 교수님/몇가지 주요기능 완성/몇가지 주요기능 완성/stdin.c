#include "header.h"

fstudent createNode(FILE *f){
    char string[80];
    fstudent fs;
    
    fs = (fstudent) malloc(sizeof(student));
    if(!fs){
        printf("노드 생성을 위한 메모리 할당에 문제가 있습니다. \n");
        return NULL;
    }
    strcpy(string, "\0");
    fgets(string, sizeof(string), f);
    sscanf(string, "%d %s %d %d %d",  &fs->num, fs->name, &fs->mid, &fs->finals, &fs->quiz);
    
    //fscanf(f, "%d %s %d %d %d", &fs->num, fs->name, &fs->mid, &fs->finals, &fs->quiz);
    //왜 안되안되...
    
    fs->next = NULL;
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
    count = i-1;
    free(fs[i-1]);
    
    for(i=0; i<count; i++)
        head = append(head, fs[i]);
    
    return head;
}

int lastnum(fstudent fs[]){
    fstudent nextnode = fs[0];
    if(!fs[0])
        return 0;
    while(nextnode->next){
        nextnode = nextnode->next;
    }
    return nextnode->num;
}
int scanLastNum(char *fname){
    fstudent fs[20];
    FILE *f;
    if((f = fopen(fname, "rb+")) == NULL){
        printf("File is not open! \n");
        return 0;
    };
    fs[0] = NULL;
    fs[0] = fillfs(f, fs);
    fclose(f);
    return lastnum(fs);
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


int saveModified(char *fname,  fstudent fs[], int lastnum){
    FILE *f;
    fstudent nextnode = fs[0];
    if((f = fopen(fname, "wb")) == NULL){
        printf("File is not open! \n");
        return 1;
    }
    while(nextnode){
        fprintf(f, "%d %s %d %d %d \n", nextnode->num, nextnode->name, nextnode->mid, nextnode->finals, nextnode->quiz);
        nextnode = nextnode->next;
    }
    
    /*for(i=0; i<lastnum; i++)
     fprintf(f, "%d %s %d %d %d\n", fs[i]->num, fs[i]->name, fs[i]->mid, fs[i]->finals, fs[i]->quiz);
     */
    fclose(f);
    return 0;
}


int modify(char fname[], int lastnum){
    FILE *f;
    fstudent fs[20];
    fstudent head = NULL;
    
    
    
    if((f = fopen(fname, "rb+")) == NULL){
        printf("File is not open! \n");
        return lastnum;
    }
    
    head = fillfs(f, fs);
    head = modifyStruct(f, fs);
    fclose(f);
    saveModified(fname, fs, lastnum);
    return lastnum;
}


int insert(char *fname, int lastnum){
    FILE *f;
    char string[80] = {'\0'};
    fstudent fs = (struct student*) malloc(sizeof(student));
    
    if((f = fopen(fname, "ab")) == NULL){
        printf("File is not open! \n");
        return lastnum;
    };
    printf("추가할 정보: ");
    fflush(stdin);
    fgets(string, sizeof(string), stdin);
    
    
    while(strcmp(string, "quit\n")){
        sscanf(string, "%s %d %d %d", fs->name, &fs->mid, &fs->finals, &fs->quiz);
        fs->num = ++lastnum;
        
        fprintf(f, "%d %s %d %d %d\n", fs->num, fs->name, fs->mid, fs->finals, fs->quiz);
        printf("추가할 정보: ");
        fflush(stdin);
        fgets(string, sizeof(string), stdin);
    }
    //fseek(f, -2L, SEEK_CUR);
    //printf("%d \n", ftell(f));
    //fprintf(f, "%c", '\0');
    
    fclose(f);
    return fs->num;
}

fstudent modNum(fstudent fs[], fstudent cur){
    fstudent nextnode;
    nextnode = cur;
    while(nextnode){
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


int deleteOne(char fname[], int lastnum){
    FILE *f;
    fstudent fs[20] = {0};
    fstudent head = NULL;
    
    if((f = fopen(fname, "rb+")) == NULL){
        printf("File is not open! \n");
        return 1;
    };
    
    head = fillfs(f, fs);
    head = deleteStruct(fs, head);
    lastnum--;
    saveModified(fname, fs, lastnum);
    fclose(f);
    return lastnum;
}
