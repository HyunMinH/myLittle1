//
//  main.c
//  길찾기
//
//  Created by 한현민 on 2016. 10. 11..
//  Copyright © 2016년 한현민. All rights reserved.
//

#include <stdio.h>


int arr[200][200], trc[200], mintrack[10], track[10];
int a=9999, *min=&a, b=0, *ind=&b,stac[200];

void prin(int num){
    int i;
    
    printf("%c", num);
    
    if(num=='J') return;
    
    printf(">");
    
    for(i=1; i<*ind; i++){
        if((arr[num][mintrack[i]]!=0 || arr[mintrack[i]][num]!=0)&& stac[mintrack[i]] !=1){
            stac[mintrack[i]]=1;
            prin(mintrack[i]);
            return;
        }
        
    }
    
}

void min_trace(int number){
    
    if(number=='J'+1) return;
    
    if (trc[number] ==1){
        mintrack[*ind]=number;
        *ind = *ind+1;
    }
    
    min_trace(number+1);
    
}



void gogo(int first, int sum){
    int idx=first+1, ye=1;


    if(first>'J') return;
    else if(first=='J'){
        if(sum<=*min){
            *ind=0;
            *min=sum;
            min_trace('A');
        }
        return;
    }else{
        while(1){
            if(trc[idx]!=1){
                if(arr[first][idx]!=0){
                    trc[idx]=1;
                    gogo(idx, sum+arr[first][idx]);
                    trc[idx]=0;
                }else if(arr[idx][first]!=0){
                    trc[idx]=1;
                    gogo(idx,sum+arr[idx][first]);
                    trc[idx]=0;
                }
            }
            
            idx+=ye;
            
            if(idx>'J'){
                ye=-1;
                idx='I';
            }else if(idx=='A') break;
            
        }
        
    }
    
}

int main(void){
    int i,j;
    
    
    for(i='A'; i<='J'; i++) trc[i]=-1;

    
    for(i='A'; i<='J'+1; i++)
        for(j='A'; j<='J'+1; j++) arr[i][j]=0;
    
    arr['A']['B']=20; arr['A']['E']=30; arr['A']['F']=10;
    arr['B']['C']=20;
    arr['C']['D']=10; arr['C']['F']=5; arr['C']['H']=20;
    arr['D']['F']=30; arr['D']['J']=20;
    arr['E']['F']=50; arr['E']['G']=40; arr['E']['I']=100;
    arr['F']['G']=10;
    arr['G']['H']=80;
    arr['H']['I']=5; arr['H']['J']=5;
    arr['I']['J']=30;
    
    trc['A']=1;
    
    gogo('A', 0);
    
    printf("%d\n", *min);
    
    prin('A');
    
    printf("\n");
    
    return 0;
    
}