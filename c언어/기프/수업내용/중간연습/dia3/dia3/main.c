#include <stdio.h>


#define LIMIT(n) (2*n-1)


int scan(){
    int n;
    
    for(;;){
        printf("숫자를 입력하세요.: ");
        scanf("%d", &n);
        
        if(n>0) break;
        else printf("다시 입력하세요. \n");
    }
    return n;
}



void prin(int n){
    char ch='a';
    int y, x, li=0;
    
    for(y=1; y<=/*세모로 하고 싶으면 n으로 바꾸셈*/LIMIT(n); y++){//1번
        //ch='a';//2번
        for(x=1; x<=LIMIT(n); x++){
            
            if(x>=n-li && x<=n) printf("%c ",ch+(n-x)/*ch++*/);//2번
            else if(x>n && x<=n+li) printf("%c ",ch+(x-n)/*ch++*/);//2번
            else printf("  ");
        }
        
        if(y>=n){
            li--;
            //ch--;//3번
        }else{
            li++;
            //ch++;//3번
        }
        
        printf("\n");
        
    }
    
}

int main(void){
    
    prin(scan());
    
    return 0;
}