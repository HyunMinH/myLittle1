#include <stdio.h>

#define MAX 8


void scanArr(int arr[], int n){
    int i;
    
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}


int scanTheNum(){
    int ret;
    
    while(1){
        printf("수열의 크기를 입력하세요: ");
        scanf("%d", &ret);
        
        if(ret>0 && ret<=8) break;
        else printf("다시 입력하세요. \n");
    }
    return ret;
}


int IFIncArr(int arr[], int n){
    int ret = 0, i;
    
    for(i=0; i<n; i++)
        if(arr[i] < arr[i+1]) ret++;
    
    if(ret == n-1) return 1;
    else return 0;
}


void turnArr(int arr[], int thenum, int start){
    int temp[MAX] = {0}, i;
    
    for(i=start; i <= start+thenum; i++){
        temp[start+thenum - i] = arr[i];
    }
    for(i=start; i <= start+thenum; i++){
        arr[i] = temp[i];
    }
}


void turnBack(int arr[], int thenum, int start){
    int temp[MAX] = {0}, i;
    
    for(i=start; i < start+thenum; i++){
        temp[start+thenum - 1] = arr[i];
    }
    for(i=start; i < start+thenum; i++){
        arr[i] = temp[i];
    }
}


// 코드를 뜯어고쳐야함!
int findLeastTry(int arr[], int thenum, int start, int n, int try, int laststart){
    int ret = 0, min = 10000;
    
    //if(start == laststart) start++;
    //if(try == 1) turnArr(arr, thenum, start);
    
    for(thenum = 0; thenum <= n; thenum++){
        for(start = 0; start < n; start++){
            /*ret = 1 + findLeastTry(arr, thenum, start, n, 1, start);
            
            if(IFIncArr(arr, n)){
                turnBack(arr, thenum, start);
                return 1;
            }
            
            if(min > ret) min = ret;*/
        }
    }
    
    //turnBack(arr, thenum, start);
    return ret;
}



int main(int argc, const char * argv[]) {
    int arr[MAX] = {0};
    int n;
    
    n = scanTheNum();
    scanArr(arr, n);
    
    printf(" %d \n",findLeastTry(arr, 0, 0, n, 0, -1));
}
