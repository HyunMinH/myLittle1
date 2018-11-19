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


int insert(FILE *f, char *fname);
int deleteOne(FILE *f, char fname[]);
int modify(FILE *f, char fname[]);

int searchOne(FILE *f, char *fname);
int stdoutAll(FILE *f, char *fname);
