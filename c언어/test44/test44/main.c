#include "Header.h"


void prin(int teamnum, int rep[]){
    int i;
    
    printf("%d \n", teamnum);
    
    for(i=0; i<teamnum; i++)
        printf("%d ", rep[i]);
}



void putLink(struct person man[], int man1, int man2){
    man[ man1 ].linkedwith[ *man[man1].linkednum ] = man2;
    *man[man1].linkednum += 1;
    
    man[ man2 ].linkedwith[ *man[man2].linkednum ] = man1;
    *man[man2].linkednum += 1;
    
}



void scanLink(struct person man[], int M, int N){
    int i, pidx1, pidx2;
    
    for(i=0; i<M; i++){
        printf("연결되어 있는 두 사람을 입력하세요. \n");
        scanf("%d%d", &pidx1, &pidx2);
        
        if(pidx1 < 0 || pidx1 > N){
            if(pidx2 < 0 || pidx2 > N){
                i--;
                printf("입력 오류입니다.  다시 입력하세요. \n");
            }
        }else{
            putLink(man, pidx1-1, pidx2-1);
        }
    }
}



int scanNumOFRealation(){
    int num;
    
    while(1){
        printf("관계의 수를 입력하세요(1~100): ");
        scanf("%d", &num);
        
        if(num >= 1 && num <= 100) break;
        else printf("다시 입력하세요. \n");
    }
    return num;
}



int scanManNum(){
    int num;
    
    while(1){
        printf("사람의 수를 입력하세요(1~100): ");
        scanf("%d", &num);
        
        if(num >= 1 && num <= MAX) break;
        else printf("다시 입력하세요. \n");
    }
    return num;
}


void pointerLinkTeam(struct team team[]){
    int i;
    
    for(i=0; i<TEAM; i++)
        team[i].p = &team[i].num;
}


void pointerLinkPerson(struct person man[], int N){
    int i;
    
    for(i=0; i<N; i++)
        man[i].linkednum = &man[i].num;
    
    for(i=0; i<N; i++)
        man[i].hp = &man[i].haveteam;
}





void resetAlrdy(int alrdyin[], int N){
    int i;
    
    for(i=0; i<N; i++)
        alrdyin[i] = 0;
}




int checkAtoB(struct person man[], int A, int B, int alrdyin[]){
    int ret=0, i, min = 9999;
    
    if(A == B) return 0;
    
    for(i=0; i<man[A].num; i++){
        if(!alrdyin[A]){
            alrdyin[A] = 1;
            ret = 1 + checkAtoB(man, man[A].linkedwith[i], B, alrdyin);
            
            if(min > ret)
                min = ret;
            
            alrdyin[A] = 0;
        }
    }
    
    return min;
}



int smallestRouteTeam1(struct person man[], struct team team[], int N, int tnum){
    int Aidx, Bidx, len = 0, min = 9999, ret = -1;
    
    int alrdyin[MAX] = {0};
    
    for(Bidx=0; Bidx<team[tnum].num; Bidx++){
        len = 0;
        
        for(Aidx=0; Aidx<team[tnum].num; Aidx++){
            resetAlrdy(alrdyin, N);
            if(!(Aidx == Bidx))
                len += checkAtoB(man, team[tnum].person[Aidx], team[tnum].person[Bidx], alrdyin);
        }
        
        if(min > len){
            min = len;
            ret = team[tnum].person[Bidx];
        }
    }
    
    return ret;
}




void findRep(struct person man[], struct team team[], int N, int rep[], int teamnum){
    int i;
    
    for(i=0; i<teamnum; i++){
        rep[i] = smallestRouteTeam1(man, team, N, i);
        
        printf("%d \n", rep[i]+1);
    }
}










int checkAllIn(struct person man[], int N){
    int i, ret = 0;
    
    for(i=0; i<N; i++)
        if(man[i].haveteam)
            ret++;
    
    if(ret == N)
        return ret;
    else
        return 0;
}


void makeTeam1(struct person man[], struct team team[], int N, int person, int teamnum){
    int i;
    
    if(checkAllIn(man, N))
        return;
    
    if(!man[person].haveteam){
        team[teamnum].person[ team[teamnum].num ] = person;
        *team[teamnum].p += 1;
        
        *man[person].hp = 1;
        
        for(i=0; i<man[person].num; i++)
            makeTeam1(man, team, N, man[person].linkedwith[i], teamnum);
    }
}



int makeTeam(struct person man[], struct team team[], int N){
    int person, teamnum = 0;
    
    for(person=0; person < N; person++){
        if(!man[person].haveteam){
            makeTeam1(man, team, N, person, teamnum);
            teamnum++;
        }
    }
    return teamnum;
}











int main(int argc, const char * argv[]) {
    int N, M, teamnum;
    int rep[MAX] = {0};
    
    struct person man[MAX] = {{0}, {0}};
    struct team team[TEAM] = {0};
    
    
    N = scanManNum();
    M = scanNumOFRealation();
    
    pointerLinkPerson(man, N);
    pointerLinkTeam(team);
    
    scanLink(man, M, N);
    
    teamnum = makeTeam(man, team, N);
    
    printf("%d \n", teamnum);
    
    findRep(man, team, N, rep, teamnum);
    
    return 0;
}
