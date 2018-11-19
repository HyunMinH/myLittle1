#include <stdio.h>
#include <string.h>

#define NAME_LEN 30
#define PHONE_LEN 30



typedef struct clientInfo{
    char name[NAME_LEN];
    char phone[PHONE_LEN];
}ClientInfo;
typedef ClientInfo LData;


typedef struct __namecard{
    LData data;
    struct __namecard *next;
}NameCard;


typedef struct _num{
    int num;
    struct _num *next;
}LNum;



typedef NameCard List;

