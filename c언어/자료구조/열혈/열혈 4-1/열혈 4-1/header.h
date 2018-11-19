#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct _point{
    int xpos;
    int ypos;
}Point;


typedef Point LData;


typedef struct node{
    LData data;
    struct node* next;
}NODE;


typedef struct _linkdedlist{
    NODE* head;
    NODE* cur;
    NODE* pre;
    int (*comp)(LData d1, LData d2);
}LinkedList;
typedef LinkedList List;



void createNode(List* list, LData data);
void append(List* list, NODE* add);
void prinNode(List* list);
void listInit(List* list);
void prinData(LData* data);
void setSortRule(List* list, int (*comp)(LData d1, LData d2));
