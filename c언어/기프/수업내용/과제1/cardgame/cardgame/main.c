#include "card.h"


void print(card temp[], int cnt){
    int i;
    
    printf("%d회차 시행...\n", cnt);
    for(i=0; i<ONEHAVE; i++)
        printf("%s of %s \n", strface[ temp[i].face ], strsuit[ temp[i].suit ]);
}


void filldeck(card *deck){
    int i;
    
    for(i=0; i<CARDMAX; i++){
        deck[i].face = i %13;
        deck[i].suit = i/13;
    }
}



void shuffle(card *deck){
    int i, j;
    card temp;
    
    for(i = 0; i<CARDMAX; i++){
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


void changeCard(card *temp1, card *temp2){
    card emptycard;
    
    emptycard.face = temp1->face;
    temp1->face = temp2->face;
    temp2->face = emptycard.face;
    
    emptycard.suit = temp1->suit;
    temp1->suit = temp2->suit;
    temp2->suit = emptycard.suit;
}



void ordify(card temp[CARDMAX]){
    int i, j;
    
    for(i=0; i<ONEHAVE; i++){
        for(j=i+1; j<ONEHAVE; j++){
            if(temp[i].face > temp[j].face)
                changeCard(&temp[i], &temp[j]);
        }
    }
}


void deal(card *deck, card temp[]){
    int i;

    for(i=0; i<ONEHAVE; i++){
        temp[i].face = deck[i].face;
        temp[i].suit = deck[i].suit;
    }
}




int checkStrt(card temp[], int start, int num){
    if(num == 4) return 1;
    
    if(start == 7) return 0;
    
    if(start == 6 && temp[start].face == 12 && temp[0].face == 0){
        if(num >= 3) return 1;
        else return 0;
    }
    if(!(temp[start+1].face - temp[start].face))
        return checkStrt(temp, start+1, num);
    else if((temp[start+1].face - temp[start].face) != 1)
        return checkStrt(temp, start+1, 0);
    
    return checkStrt(temp, start+1, num+1);
}






void findStrt(card *deck){
    card temp[ONEHAVE];
    int cnt = 0;
    
    while(1){
        deal(deck, temp);
        ordify(temp);
        
        cnt++;
        
        if(cnt <= 2)
            print(temp, cnt);
        
        if(checkStrt(temp,0,0))
            break;
        
        if(cnt <= 2)
            printf("\nNot Straight! \n\n\n");
        
        shuffle(deck);
    }

    if(cnt > 2)
        print(temp, cnt);
    printf("\n%d회차 실행 Straight! \n\n\n", cnt);
}



int main(){
    card deck[CARDMAX];
    
    srand(time(NULL));
    
    filldeck(deck);
    shuffle(deck);
    
    
    
    findStrt(deck);
    
}
