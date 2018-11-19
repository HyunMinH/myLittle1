//
//  card.h
//  오상이 card
//
//  Created by 한현민 on 2016. 11. 11..
//  Copyright © 2016년 한현민. All rights reserved.
//

#ifndef card_h
#define card_h


#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#define count 7
enum enumsuit {Hearts,Diamonds,Clubs,Spades};
enum enumface {Ace,Deuce,Three,Four,Five,Six,Seven,
    Eight,Nine,Ten,Jack,Queen,King};
typedef enum enumsuit enumsuit;
typedef enum enumface enumface;

struct card {
    int suit;
    int face;
};
typedef struct card card;

char *strface[] = { "Ace","Deuce","Three","Four","Five","Six",
    "Seven","Eight","Nine","Ten","Jack","Queen","King" };
char *strsuit[] = { "Hearts","Diamonds","Clubs","Spades" };

void filldeck(card *deck);
void shuffle(card *deck);
void deal(card *deck,card *mine);
void cardprint(card *mine);
void sorting(card *mine);
int choice(card *mine,card *striaght);
int straightchecking(card *straight,int);



#endif /* card_h */
