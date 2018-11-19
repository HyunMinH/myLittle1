#include <stdio.h>

#define X(x) ((x)*(x))

int arr[20][20]={0};
int a=1, b=-1, *ax=&a, *ay=&b;

void storeNumToArr(int height, int x, int y, char ch, int n, int A, int sum);
void prinArr(int);
void ifNequalSum(int height, int x, int y, int ch, int n, int A, int sum);
void changeAxorAy(int *);
int scanHeight(int);


int main(void){
    int height;
    
    height = scanHeight(height);
    
    storeNumToArr(height, 0, 0, 'x', 1, height, height);
    prinArr(height);
    
    return 0;
}


int scanHeight(int height){
    while(1){
        printf("높이를 입력하세요.(1~9): ");
        scanf("%d", &height);
        if(height > 0 && height < 10) break;
        else printf("다시 입력하세요. \n");
    }
    
    return height;
}


void storeNumToArr(int height, int x, int y, char ch, int n, int A, int sum){
    if(n > X(height)) return;
    
    arr[y][x] = n;
    
    if(n == sum){
        ifNequalSum(height, x, y, ch, n , A, sum);
    }else{
        if(ch == 'x') storeNumToArr(height, x+ *ax,y, 'x', n+1, A, sum);
        else if(ch == 'y') storeNumToArr(height, x, y+ *ay, 'y', n+1, A, sum);
    }
    
    return;
}


void ifNequalSum(int height, int x, int y, int ch, int n, int A, int sum){
    if(ch =='x'){
        changeAxorAy(ay);
        storeNumToArr(height, x, y + *ay, 'y', n+1, A-1, sum+A-1);
    }else if(ch == 'y'){
        changeAxorAy(ax);
        storeNumToArr(height, x + *ax, y, 'x', n+1, A, sum+A);
    }
}


void changeAxorAy(int *change){
    if(*change == 1) *change = -1;
    else *change = 1;
}


void prinArr(int height){
    int y, x;
    
    for(y=0; y < height; y++){
        for(x=0; x < height; x++){
            printf("%2d ", arr[y][x]);
        }
        printf("\n");
    }
    
}
