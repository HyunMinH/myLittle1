#include <stdio.h>
#include <conio.h>
#include <string.h>

void mystrncat(char s1[], const char s2[], int size){
	int i, j;

	i= strlen(s1);

	for(j=0; j<size; j++) s1[i+j]=s2[j];

}


int main(void){
	char s1[50]="C programming";
	char* str1="show and tell";
	mystrncat(s1, str1, 6);
	printf("%s\n", s1);
	s1[14]='\0';
	mystrncat(s1, str1, 20);
	printf("%s\n", s1);

}