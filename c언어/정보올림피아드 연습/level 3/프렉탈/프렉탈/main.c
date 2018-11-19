#include <stdio.h>

#define MAX 10


char string1 = 'X';
char stringN[1000000][1000000] = {'\0'};


int HowMuchPlusXorY(int n){
    int i, ret = 1;
    
    for(i = 2; i < n; i++)
        ret *= 3;
    return ret;
}


int IFNis1(int n, int startx, int starty){
    int ret = 0;
    
    if(n == 1){
        stringN[starty][startx] = 'X';
        ret++;
    }
    return ret;
}



void saveStringN(int n, int startx, int starty){
    int firstx = startx, firsty = starty;
    
    if(IFNis1(n, startx, starty) == 1) return;

    saveStringN(n-1, startx, starty);
    
    startx += 2*HowMuchPlusXorY(n);
    saveStringN(n-1, startx, starty);
    
    startx = firstx + HowMuchPlusXorY(n);
    starty = firsty + HowMuchPlusXorY(n);
    saveStringN(n-1, startx, starty);
    
    startx = firstx;
    starty += HowMuchPlusXorY(n);
    saveStringN(n-1, startx, starty);

    startx += 2*HowMuchPlusXorY(n);
    saveStringN(n-1, startx, starty);
}


void prinStringN(n){
    int limit = 1, y, x, i;
    
    for(i = 1; i < n; i++)
        limit *= 3;
    
    for(y = 0; y < limit; y++){
        for(x = 0; x < limit; x++){
            if(stringN[y][x] == 'X') printf("X");
            else printf(" ");
        }
        printf("\n");
    }
}


int scanN(int n){
    while(1){
        printf("프렉탈 함수 차수를 입력하세요(1~10): ");
        scanf("%d", &n);
        
        if(n >= 1 && n <= 10) break;
        else printf("다시 입력하세요. \n");
    }
    return n;
}


int main(void){
    int n;
    
    n = scanN(n);
    
    saveStringN(n, 0, 0);
    prinStringN(n);
}
