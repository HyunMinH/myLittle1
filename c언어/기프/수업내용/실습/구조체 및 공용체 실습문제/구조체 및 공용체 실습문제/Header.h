#ifndef Header_h
#define Header_h



#include <stdio.h>
#include <string.h>



#define MAX 5
#define CARNAME 10
#define MADEBY 10



typedef struct car{
    char carname[CARNAME];
    int year;
    int price;
    char company[MADEBY];
    
}car;


#endif /* Header_h */
