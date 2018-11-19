#include <stdio.h>
#include <string.h>

#define SIZE 100


void final(char src[], char ist[], int index){
    printf("∞·∞˙......\n");
    printf("%s \n", src);
}


int strist(char src[], char ist[], int index){
    char temp[100]={'\0'};
    int i, tdx=0;
    
    if(strlen(src) + strlen(ist) +1 > 100) return 1;
    
    strcpy(temp, ist);
    tdx = strlen(ist);
    
    for(i=index; i < strlen(src); i++)
        temp[tdx++] = src[i];
    
    src[index] = '\0';
    strcat(src, temp);
    
    return 0;
}


int main(void){
    char src[SIZE]={'\0'}, ist[SIZE]={'\0'};
    int index;
    
    puts("ø¯∫ª πÆ¿⁄ø≠ ¿‘∑¬: ");
    gets(src);
    puts("ª¿‘«“ πÆ¿⁄ø≠ ¿‘∑¬: ");
    gets(ist);
    
    printf("ª¿‘«“ ¿ßƒ° ¿‘∑¬: ");
    scanf("%d", &index);
    
    strist(src, ist, index-1);
    
    final(src, ist, index);
}
