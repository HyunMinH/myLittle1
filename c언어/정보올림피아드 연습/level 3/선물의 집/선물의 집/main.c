#include <stdio.h>


#define MAX 10


int alreadyx[MAX] = {0}, alreadyy[MAX] = {0};



int noPath(int house[][MAX], int n, int ix, int iy){
    int ret = 0;
    
    if(ix < 0 || ix >= n)
        ret++;
    else if(iy < 0 || iy >= n)
        ret++;
    else if(house[iy][ix] == 1)
        ret++;
    
    return ret;
}


int alreadyTrace(int ix, int iy){
    int ret = 0;
    
    if(alreadyx[ix] == 1 && alreadyy[iy] == 1) ret++;
    
    return ret;
}


void eraceTrace(int ix, int iy){
    alreadyx[ix] = 0;
    alreadyy[iy] = 0;
}


void saveTrace(int ix, int iy){
    alreadyx[ix] = 1;
    alreadyy[iy] = 1;
}


int escapeHouse(int house[][MAX], int n, int ix, int iy){
    int pathplusx[4] = {0,-1,1,0};
    int pathplusy[4] = {-1, 0, 0, 1};
    int maxprisent = 0, newret, i, find = 0;
    
    
    if(noPath(house, n, ix, iy)) return 0;
    
    if(alreadyTrace(ix, iy)) return 0;
    else saveTrace(ix, iy);
    
    if(house[iy][ix] == 2) find++;
    
    for(i = 0; i < 4; i++){
        newret = find + escapeHouse(house, n, ix + pathplusx[i], iy + pathplusy[i]);
        if(newret > maxprisent)
            maxprisent = newret;
    }
    
    eraceTrace(ix, iy);
    return maxprisent;
}



void scanHouse(int house[][MAX], int n){
    int y, x;
    
    for(y = 0; y < n; y++){
        printf("%d번째 행입니다. 0은 길, 1은 벽, 2는 선물입니다.\n", y+1);
        
        for(x = 0; x < n; x++)
            scanf("%d",&house[y][x]);
    }
}



int scanLenght(int n){
    while(1){
        printf("한 변의 길이를 입력(1~10): ");
        scanf("%d", &n);
        
        if(n >= 1 && n <= 10) break;
        else printf("다시 입력하세요. \n");
    }
    return n;
}



int main(void){
    
    int n;
    int house[MAX][MAX] = { {0,1,2,0,0},
                            {0,0,0,1,0},
                            {0,1,0,1,0},
                            {0,0,2,1,0},
                            {2,1,0,0,0}};
    
    n = scanLenght(n);
    //scanHouse(house, n);
    
    printf("최대로 찾은 선물의 갯수는 %d입니다.\n", escapeHouse(house, n, 0, 0));
}
