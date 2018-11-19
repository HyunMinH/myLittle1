#include <stdio.h>
#include <string.h>
#define SIZE 50


int charTolnt(char ch){
	return ch-48;
}


void addbignumber(char num1[], char num2[], char result[],int idx1, int idx2, int idx3){
	if(idx1<=-1 && idx2<=-1) return;

	if(idx1<=-1) result[idx3]=result[idx3]+charTolnt(num2[idx2])+48;
	else if(idx2<=-1) result[idx3]=result[idx3]+charTolnt(num1[idx1])+48;
	else result[idx3]=result[idx3]+charTolnt(num1[idx1])+charTolnt(num2[idx2])+48; 

	if (result[idx3]>=58){
		result[idx3] -=10;
		result[idx3-1] +=1;
		if(idx3==1) result[idx3-1] +=48;
	}
	addbignumber(num1,num2, result, idx1-1, idx2-1, idx3-1); 
}


void getStringNum(char num1[], char num2[]){
	printf("Input num1 \n");
	gets(num1);
	printf("Input num2 \n");
	gets(num2);
}


int main(void){
	char num1[SIZE], num2[SIZE], result[SIZE+1]={'\0'};
	int idx1, idx2, idx3;

	getStringNum(num1, num2);
	
	idx1=strlen(num1)-1, idx2=strlen(num2)-1;

	idx3=(idx1>idx2) ? idx1+1 : idx2+1;

	addbignumber(num1, num2, result, idx1, idx2, idx3);

	if(result[0]=='\0') printf("%s + %s = %s\n",num1, num2, result+1);
	else printf("%s + %s = %s\n",num1, num2, result); 

	return 0;
}