//
//  main.c
//  사람감시
//
//  Created by 한현민 on 2016. 10. 9..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define R(K) (sqrt(K/(2*3.14)))
#define DISTANCE(x1,x2,y1,y2) (sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))

double manx[5000], many[5000];


void scan(int m_num){
    int i;
    
    for(i=0; i<m_num; i++){
        printf("%d번째 사람의 x,y좌표를 쓰세요: ", i+1);
        scanf("%lf%lf", &manx[i], &many[i]);
    }
}


int check(int m_num, int number, double res, int X1, int Y1, int X2, int Y2){
    // number은 몇번째 사람인가를 나타냄;
    // res는 감시원의 반지름
    int ret; //return할 값;
    
    if(number==m_num) return 0;
    
    if(res<DISTANCE(manx[number], X1, many[number], Y1)) && res<DISTANCE(manx[number], X2, many[number], Y2)))
        ret = 0 + check(m_num, number+1, res, X1, Y1, X2, Y2);
    else ret = 1 + check(m_num, number+1, res, X1, Y1, X2, Y2);
    
    return ret;
}
       

int main(void){
    int X1, Y1, X2, Y2; double K; //레이더 망의 정보들
    int m_num;// 사람숫자
    
    printf("1번째 레이더망의 x,y좌표를 쓰세요: ");
    scanf("%d%d", &X1, &Y1);
    printf("2번째 레이더망의 x,y좌표를 쓰세요: ");
    scanf("%d%d", &X2, &Y2);
    
    while(1){
        printf("레이더망의 감시영역의 넓이는 얼마입니까?: ");
        scanf("%lf", &K);
        if(K>0) break;
        else printf("크기가 0보다 작습니다.");
    }
    
    printf("사람이 몇 명 있습니까?: ");
    scanf("%d", &m_num);
    
    scan(m_num);
    
    printf("%d \n", check(m_num, 0, R(K), X1, Y1, X2, Y2));
    
    return 0;
}