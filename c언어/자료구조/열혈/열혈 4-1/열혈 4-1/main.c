#include "header.h"



void prinData(LData *data){
    printf("[%d,%d] ", data->xpos, data->ypos);
}


int scanDataInt(char ch){
    int num;
    
    printf("%c좌표를 입력하세요: ", ch);
    scanf("%d", &num);

    return num;
}



int sortRuleXY(LData point1, LData point2){
    if(point1.xpos < point2.xpos){
        return 0;
    }else if(point1.xpos == point2.xpos){
        if(point1.ypos < point2.ypos) return 0;
        else return 1;
    }else{
        return 1;
    }
}


int main(void){
    List plist;
    LData dataUsers;
    int selectNo;
    
    listInit(&plist);
    setSortRule(&plist, sortRuleXY);

    while(1){
        printf("종료하시려면 0번을 누르시고 아니면 다른 숫자를 입력하세요.\n");
        scanf("%d", &selectNo);
        if(selectNo == 0) break;
        
        dataUsers.xpos = scanDataInt('x');
        dataUsers.ypos = scanDataInt('y');
        
        createNode(&plist, dataUsers);
        append(&plist, plist.cur);
    }
    
    prinNode(&plist);
    
    return 0;
}
