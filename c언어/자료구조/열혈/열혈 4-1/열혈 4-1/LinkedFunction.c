#include "header.h"


void setSortRule(List* list, int (*comp)(LData d1, LData d2)){
    list->comp = comp;
}


void listInit(List* list){
    list->head = (NODE*) malloc(sizeof(NODE));
    list->comp =NULL;
}


NODE* dataSave(NODE* node, LData data){
    node->data = data;
    return node;
}

void createNode(List* list, LData data){
    NODE* node;
    
    node = (NODE*) malloc(sizeof(NODE));
    node = dataSave(node, data);
    node->next = NULL;
    
    list->cur = node;
}



void appendPre(List* list, NODE* add){
    NODE* nextNode;
    
    nextNode = list->head->next;
    list->head->next = add;
    add->next = nextNode;
}


void appendComp(List* list, NODE* add){
    NODE* nextNode = list->head;
    
    while(nextNode->next != NULL){
        if((list->comp(add->data, nextNode->next->data)) == 0){
            break;
        }
        nextNode = nextNode->next;
    }
    
    add->next = nextNode->next;
    nextNode->next = add;
}


void append(List* list, NODE* add){
    if(list->comp == NULL){
        appendPre(list, add);
    }else{
        appendComp(list, add);
    }
}



void prinNode(List* list){
    NODE* nextNode = list->head;
    
    if(list->head->next == NULL){
        printf("노드가 없습니다. \n");
        return;
    }
    
    while(nextNode->next != NULL){
        nextNode = nextNode->next;
        prinData(&nextNode->data);
        if(nextNode->next != NULL) printf("->");
    }
    printf("\n\n");
}
