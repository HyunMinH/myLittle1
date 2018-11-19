#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void makeComString(char comstring[]){
	int strlength, i, bigorsmall;
	strlength=rand()%7+5;
	for(i=0; i<strlength; i++){
		bigorsmall=rand()%1;
		if(bigorsmall==1) comstring[i] = rand()%26+65;
		else comstring[i] = rand()%26+97;
	}
}

void makeManString(char manstring[]){
	char string1[100];

	while(1){
		printf("문자열 입력(길이 5~12):\n");
		scanf("%s", string1);
		if(strlen(string1)>=5 && strlen(string1)<=12){
			strcpy(manstring, string1);
			break;
		}else printf("다시 입력하세요. \n");
	}
}


int main(void){
	char manstring[100], comstring[100]={'\0'};
	long seed;
	seed=time(NULL);
	srand(seed);

	makeComString(comstring);
	makeManString(manstring);
	printf("컴퓨터의 문자열:\n%s", comstring);

	printf("\n%s", strcmp(manstring, comstring)>0 ? "컴퓨터 승! \n" : strcmp(manstring, comstring)<0 ? "사용자 승! \n" : "비겼음! \n");
	return 0;
}