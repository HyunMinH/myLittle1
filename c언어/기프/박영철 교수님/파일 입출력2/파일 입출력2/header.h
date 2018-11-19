#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define A 200
#define B 150
#define C


typedef struct student{
    int num;
    char name[30];
    int mid, finals, quiz;
    int sum, avg;
    char grade;
    struct student *love;
    struct student *next;
}student;

typedef student *fstudent;


int insert(char *fname, int);
int deleteOne(char fname[]);
int modify(char fname[]);

int searchOne( char *fname);
int stdoutAll(char *fname);
int scanLastNum(char *fname);
