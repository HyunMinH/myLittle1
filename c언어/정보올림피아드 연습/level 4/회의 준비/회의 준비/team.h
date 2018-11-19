//
//  team.h
//  회의 준비
//
//  Created by 한현민 on 2016. 11. 7..
//  Copyright © 2016년 한현민. All rights reserved.
//

#ifndef team_h
#define team_h

#include <stdio.h>
#include <string.h>


#define MAX 100


struct man{
    int ifteam;
    int liked[MAX];
    int likedmax;
    
};


void makeTeam(struct man man1[MAX] , int num, int teamnum, int team[][MAX]);
int alreadyIn(int team[][MAX], int teamnum, int num, int index);

#endif /* team_h */
