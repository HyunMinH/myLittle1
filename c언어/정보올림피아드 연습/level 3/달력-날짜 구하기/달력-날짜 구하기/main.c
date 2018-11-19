//
//  main.c
//  달력-날짜 구하기
//
//  Created by 한현민 on 2016. 10. 6..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>
#define IFONE(x) (x%4==0 && x%100!= 0) || x%400 ==0

void calc_31(int number, int day[]);
void calc_30(int number, int day[]);
void calc_29(int number, int day[]);
void calc_28(int number, int day[]);

void calc_31(int number, int day[]){
    
    if(number==0) return;
    
    while(1){
        
        if(number>=365){
            day[0] = day[0]+1;
            number -= 365;
        }else{
            if(number>=31){
                day[1]++;
                number -= 31;
                
                if(IFONE(day[0])==1 && day[1]==2){
                    calc_29(number, day);
                }else if(day[1]==2){
                    calc_28(number, day);
                }else if(day[1]==13){
                    day[1]=1;
                    calc_31(number, day);
                }else if(day[1]==7){
                    calc_31(number, day);
                }else calc_30(number, day);
            }
            break;
        }
        
    }
    
    day[2] += number;
    if(day[2]>31){
        day[1]++;
        number = 0;
        day[2] -= 31;
        if(day[1]==13) day[1]=1;
    }
    
}

void calc_30(int number, int day[]){
    
    if(number==0) return;
    
    while(1){
        
        if(number>=365){
            day[0] = day[0]+1;
            number -= 365;
        }else{
            if(number>=30){
                day[1]++;
                number -= 30;
                calc_31(number, day);
            }
            break;
        }
    }
    
    day[2] += number;
    if(day[2]>30){
        day[1]++;
        number=0;
        day[2] -= 31;
    }
}

void calc_29(int number, int day[]){
    
    if(number ==0) return;
    
    while(1){
        
        if(number>=366){
            day[0] = day[0]+1;
            number -=366;
        }else{
            if(number>=29){
                day[1]++;
                number -=29;
                calc_31(number, day);
            }
            break;
        }
        
    }
    day[2] += number;
    if(day[2]>29){
        day[1]++;
        number=0;
        day[2] -= 29;
    }
}

void calc_28(int number, int day[]){
    
    if(number ==0) return;
    
    while(1){
        
        if(number>=365){
            day[0] = day[0]+1;
            number -=365;
        }else{
            if(number>=28){
                day[1]++;
                number -=28;
                calc_31(number, day);
            }
            break;
        }
        
    }
    day[2] += number;
    if(day[2]>28){
        day[1]++;
        number=0;
        day[2] -= 28;
    }

}


int main(void){
    int day[3],number;
    char a; //요일
    
    printf("처음 년도 달 일 요일을 입력하세요. \n");
    scanf("%d", &day[0]);
    scanf("%d", &day[1]);
    scanf("%d", &day[2]);
    scanf("\n%c", &a);
    printf("처음 년도 달 일 요일은 %d년 %d월 %d일 %d요일 입니다.", day[0], day[1], day[2], a);
    
    while(1){
        puts("몇 일뒤를 출력하시겠습니까?(-1)은 종료");
        scanf("%d", &number);
        
        calc_31(number, day);
        
        printf("%d %d %d ", day[0], day[1], day[2]);
        
        if(number==-1) break;
        else if(number>9999 || number<1) puts("다시 입력하세요.");
        

    }
    
}