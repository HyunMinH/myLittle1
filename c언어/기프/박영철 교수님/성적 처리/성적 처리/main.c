#include <stdio.h>

void swi(int sub[3], char sub_grade[4]){
    int box=0, i, j, vc[3]={sub[0], sub[1], sub[2]};
    char a[]="cba";
    
    for(i=0; i<3; i++)
        for(j=i+1; j<3; j++)
            if (vc[i]>=vc[j]){
                box=vc[i];
                vc[i]=vc[j];
                vc[j]=box;
            }
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(vc[j]==sub[i]) sub_grade[i] = a[j];
}

int main(void){
    int math[3], eng[3], kor[3], i;
    char name[3][20];
    char math_grade[4], eng_grade[4], kor_grade[4];
    
    for(i=0; i<3; i++){
        printf("이름과 국어, 영어, 수학 성적을 입력하시오: ");
        scanf("%s%d%d%d", name[i], &kor[i], &eng[i], &math[i]);
        fflush(stdin);
    }
    
    swi(math, math_grade);  swi(kor, kor_grade);  swi(eng, eng_grade);
    
    for(i=0; i<3; i++)
        printf("\t %s:%d(%c)  %d(%c)  %d(%c) \n", name[i], kor[i], kor_grade[i], eng[i], eng_grade[i], math[i], math_grade[i]);
}