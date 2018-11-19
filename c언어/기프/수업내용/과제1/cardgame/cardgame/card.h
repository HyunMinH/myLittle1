//
//  card.h
//  cardgame
//
//  Created by 한현민 on 2016. 11. 10..
//  Copyright © 2016년 한현민. All rights reserved.
//

#ifndef card_h
#define card_h


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define CARDMAX 52
#define ONEHAVE 7


enum enumsuit {Hearts, Diamonds, Clubs, Spades};
enum enumface {Ace, Deuce, Three, Four, Five, Six, Seven,
    Eight, Nine, Ten, Jack, Queen, King};

typedef enum enumsuit enumsuit;
typedef enum enumface enumface;


struct card{
    enumsuit suit;
    enumface face;
};
typedef struct card card;


char *strface[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
char *strsuit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};


void filldeck(card *deck);
void shuffle(card *deck);
void deal(card *deck, card temp[ONEHAVE]);



#endif /* card_h */
