#include "Header.h"
#include <stdlib.h>



List* createNode(LData* data){
    List* cur;
    cur = (List *) malloc(sizeof(List));
    
    if(cur == NULL) return NULL;
    
    cur->data = *data;
    cur->next = NULL;
    
    return cur;
}


List* append(List* head, List* cur){
    List* nextNode = head;
    
    if(head == NULL){
        return cur;
    }
    
    while(nextNode->next != NULL){
        nextNode = nextNode->next;
    }
    nextNode->next = cur;
    
    return head;
}

/*
int LSum(List* head){
    int sum = 0;
    List* nextnode = head;
    
    while(nextnode != NULL){
        sum += nextnode->num;
        nextnode = nextnode->next;
    }
    
    return sum;
}
*/


void printNameCard(LData data){
    printf("\n[Name]: %s\n", data.name);
    printf("[Phone]: %s\n", data.phone);
}


void printList(List* head){
    List* nextNode = head;
    
    printf("--리스트 목록-- \n");
    while(nextNode != NULL){
        printNameCard(nextNode->data);
        
        if(nextNode->next) printf("->");
        else printf("\n");
        
        nextNode = nextNode->next;
    }
}


int nameCompare(ClientInfo CData, ClientInfo wanted){
    if(strcmp(CData.name, wanted.name) == 0){
        return 0;
    }else{
        return 1;
    }
}


List* LRemove(List* head, LData wanted){
    List* nextNode;
    List* preNode = NULL;
    
    if(head == NULL){
        printf("노드가 없습니다.\n");
        return NULL;
    }
    
    while(nameCompare(head->data, wanted) == 0){
        preNode = head;
        head = head->next;
        free(preNode);
        
        if(head == NULL) return NULL;
    }
    
    nextNode = head;
    
    while(nextNode->next != NULL){
        if(nameCompare(head->next->data, wanted) == 0){
            preNode = nextNode;
            nextNode = nextNode->next;
            preNode->next = nextNode->next;
            
            free(nextNode);
            nextNode = preNode->next;
            
            if(nextNode == NULL) break;
        }else{
            nextNode = nextNode->next;
        }
    }
    
    return head;
}


LData* saveData(){
    LData* data = (LData*) malloc(sizeof(LData));
    
    printf("name: ");
    scanf("%s", data->name);
    printf("phone: ");
    scanf("%s", data->phone);
    
    return data;
}


int main(int argc, const char * argv[]) {
    List* curNode;
    List* head = NULL;
    LData* data;
    
    while(1){
        int selectNo;
        
        data = saveData();
        curNode = createNode(data);
        
        if(curNode == NULL){
            printf("동적 메모리 할당에 문제가 있습니다. \n");
            exit(1);
        }
        
        head = append(head, curNode);
        
        printf("1. 종료 아무숫자: 계속: ");
        scanf("%d", &selectNo);
        if(selectNo == 1) break;
    }
    
    printList(head);
    
    while(1){
        LData* wanted = (LData*) malloc(sizeof(LData));
        
        printf("삭제할 이름: ");
        scanf("%s", wanted->name);
        
        head = LRemove(head, *wanted);
        printList(head);
    }
    
    return 0;
}


