#include "team.h"





int alreadyIn(int team[][MAX], int teamnum, int num, int index){
    int i, ret = 0;
    
    for(i=0; i<index; i++){
        if(team[teamnum][i] == num) ret++;
    }
    return ret;
}


int nextStart(int team[][MAX], int teamnum, int index, int N, int teamnum){
    int ret = -1, i;
    
    for(i=0; i<N; i++)
        if(!alreadyIn(team, teamnum, i, index)){
            ret = i;
            break;
        }
    return i;
}



int makeTeamOne(struct man man1[MAX] , int num, int teamnum, int team[][MAX]){
    int i;
    static int index = 0;
    
    for(i=0; i<=man1[num].likedmax; i++){
        if(!alreadyIn(team, teamnum, man1[num].liked[i], index)){
            team[teamnum][index++] = man1[num].liked[i];
            makeTeam(man1, man1[num].liked[i], teamnum, team);
        }
    }
    return index;
}


void team(struct man man1[MAX], int num, int team[][MAX], int N){
    int teamnum, mannum;
    
    
    
    
}
