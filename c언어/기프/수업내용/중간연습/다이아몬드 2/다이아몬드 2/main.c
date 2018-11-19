#include <stdio.h>

#define limit(n) ('a' + 2*n-1)

int scan(){
    int n;
    
    while(1){
        printf("몇 줄 할겁니까?: ");
        scanf("%d", &n);
        
        if(n>0) break;
        else printf("숫자가 1보다 작습니다.\n");
    }
    
    return n;
}


void prindia(int n){
    int y,x,ye=0;
    
    for(y='a'; y<limit(n); y++){
        
        for(x='a'; x<=limit(n); x++){
            if(x>='a'+n-ye && x<='a'+n+ye) printf("%c ", x);
            else printf("  ");
        }
        
        if(y>='a'+n-1) ye--;
        else ye++;
        
        printf("\n");
    }
    
}


int main(void){
    
    prindia( scan() );
    
    return 0;
}
