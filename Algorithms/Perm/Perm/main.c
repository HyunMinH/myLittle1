//
//  main.c
//  Perm
//
//  Created by 한현민 on 2018. 4. 2..
//  Copyright © 2018년 한현민. All rights reserved.
//

#include <stdio.h>
#include <string.h>


#define CHANGE(x,y,t) ((t=x), (x=y), (y=t))


void sort(char* a, int k, int n){
    int i, j, temp;
    for(i=k; i<n; i++){
        for(j=i+1; j<n; j++){
            if(a[i] > a[j])
                CHANGE(a[i], a[j], temp);
        }
    }
}

int hasMST(char* a, int k, int n){
    int i;
    for(i=k+1; i<n; i++){
        if(a[i] > a[k])
            return i;
    }
    
    return -1;
}

void perm(char* a, int k, int n){
    int temp, m;
    
    if(k >= n){
        printf("%s\n", a);
        return;
    }
    
    sort(a, k, n);
    perm(a, k+1, n);
    sort(a, k+1, n);
    
    while((m = hasMST(a, k, n)) > -1){
        CHANGE(a[k], a[m], temp);
        perm(a, k+1, n);
        sort(a, k+1, n);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char a[10000];
    
    scanf("%s", a);
    perm(a, 0, (int)strlen(a));
    return 0;
}
