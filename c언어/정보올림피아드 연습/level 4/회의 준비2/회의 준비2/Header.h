//
//  Header.h
//  회의 준비2
//
//  Created by 한현민 on 2016. 11. 9..
//  Copyright © 2016년 한현민. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <stdio.h>
#include <string.h>



#define MAX 100
#define TEAM 10


struct  person{
    int linkedwith[MAX];
    int num;
    int *linkednum;
    int haveteam;
    int *hp;
};


struct team{
    int person[MAX];
    int num;
    int *p;
};



#endif /* Header_h */
