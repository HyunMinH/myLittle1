//
//  card.h
//  현섭 스트레이트
//
//  Created by 한현민 on 2016. 11. 14..
//  Copyright © 2016년 한현민. All rights reserved.
//

#ifndef card_h
#define card_h

#include <stdlib.h>
#include <time.h>

enum enumsuit {hearts,diamonds,clubs,spades};
enum enumface {ace,deuce,three,four,five,six,seven,eight,nine,ten,jack,queen,king};

typedef enum enumsuit enumsuit;
typedef enum enumface enumface;

struct card
{
    enumsuit suit;
    enumface face;
};
typedef struct card card;

char *strface[]={"ace","deuce","three","four","five","six","seven","eight","nine","ten","jack","queen","king"};
char *strsuit[]={"hearts","diamonds","clubs","spades"};

void filldeck(card *deck);
void shuffle(card *deck);
void deal(card *deck);
int straight(card *deck);


#endif /* card_h */
