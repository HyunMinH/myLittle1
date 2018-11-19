//
//  main.c
//  와일드 카드
//
//  Created by 한현민 on 2016. 10. 8..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char PILE[50][11], Real_PILE[11];


void scan(int pile_number){
    int i;
    char A[1000]; // PILE[]에 넣기전에 문자의 갯수를 체크;
    
    for(i=0; i<pile_number; i++){
        printf("%d번째 pile명을 입력하세요:(1~10사이의 갯수) ", i+1);
        scanf("%s",A);
        if(strlen(A)>0 && strlen(A)<=10) memcpy(PILE[i], A, strlen(A)+1);
        else {
            printf("크기 오류입니다!! 다시 입력하세요. \n");
            i--;
        }
        
    }
    
}




int find_where_np(int snum, int cnum, int rcnum, int index, int *ret ){
    // 여기서 rcnum은 *의 위치
    //*ret은 return 할 값
    if(cnum+index<strlen(PILE[snum])-(strlen(Real_PILE)-rcnum-1) ){
        if(Real_PILE[rcnum+1] == PILE[snum][cnum+index]){
            *ret = *ret+1;
            find_where_np(snum, cnum, rcnum, index+1, ret);
        }
        else find_where_np(snum, cnum, rcnum, index+1, ret);
    }
    
    return *ret;
}




int samecheck(int snum, int cnum, int rcnum){
    int cnum2, a=1, ret=0;
    //*check_same 몇개나 맞는지
    
    if(cnum==strlen(PILE[snum])){
        return 0;
    }else if(Real_PILE[rcnum]=='?') {
        ret = 1 + samecheck(snum, cnum+1, rcnum+1);
    }else if(Real_PILE[rcnum]=='*') {
        if(rcnum+1==strlen(Real_PILE)){
            return 1;
        }
        cnum2 = find_where_np(snum, cnum, rcnum, 1, &a);
        ret = cnum2 + samecheck(snum, cnum + cnum2, rcnum+1);
    }else if(PILE[snum][cnum]==Real_PILE[rcnum]) {
        ret = 1 + samecheck(snum, cnum+1, rcnum+1);
    }else return 0;
    
    return ret;
}



int main(void){
    int Case, pile_number, i, snum, answer=0;
    char A[1000]; //Real_PILE에 넣기전에 문자의 갯수를 체크;
    
    while(1){
        printf("케이스의 수를 입력하세요(1~10): ");
        scanf("%d", &Case);
        if (Case>=1 && Case<=10) break;
    }
    
    for(i=0; i<Case; i++){
        printf("%d번째 케이스입니다.\n", i+1);
        
        while(1){
            printf("문자열을 입력하세요(1~10 사이의 갯수): ");
            scanf("%s", A);
            if(strlen(A)>0 && strlen(A)<=10) {
                memcpy(Real_PILE, A, strlen(A)+1);
                break;
            }
            else printf("크기 오류입니다!! 다시 입력하세요. \n");
        }
        
        while(1){
            printf("파일명의 수를 입력하세요(1~50): ");
            scanf("%d", &pile_number);
            if(pile_number>=1 && pile_number<=50) break;
        }
        
        scan(pile_number);
        
        for(snum=0; snum<pile_number; snum++){
            if(samecheck(snum, 0,0)==strlen(PILE[snum])) answer++;
        }
        
        printf("%d\n\n", answer);
        
    }
    
}



