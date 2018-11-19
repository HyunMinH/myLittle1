#include "card.h"

#include <stdio.h>

void filldeck(card *deck)
{
    int i;
    for(i=0;i<51;i++)
    {
        deck[i].face=i%13;
        deck[i].suit=i/13;
    }
}
void suffle(card *deck)
{
    int i,j;
    card temp;
    
    for(i=0;i<=51;i++)
    {
        j=rand()%52;
        temp=deck[i];
        deck[i]=deck[j];
        deck[j]=temp;
    }
}

void deal(card *deck)
{
    int i,j;
    card temp;
    for(i=0;i<7;i++)
    {
        for(j=i+1;j<7;j++)
        {
            if(deck[i].face>deck[j].face)
            {
                temp=deck[i];
                deck[i]=deck[j];
                deck[j]=temp;
            }
        }
    }
}

void prin(card deck[]){
    int i;
    for(i=0;i<7;i++)
    {
        printf("%5s of %-8s%c",strface[deck[i].face],strsuit[deck[i].suit],'\n');
    }
}

int straight(card *deck)
{
    int i;
    int count=0;
    int find[13]={0};
    
    for(i=0;i<7;i++)
    {
        find[deck[i].face]=1;
    }
    for(i=0;i<13;i++)
    {
        if(find[i]==1&&find[i+1]==1)
        {
            count++;
        }
        else
        {
            count=0;
        }
        
        if(count==4)
        {
            return 1;
        }
        
        if(find[0]==1&&find[12]==1&&find[11]==1&&find[10]==1&&find[9]==1)
        {
            return 1;
        }
        
    }
    return 0;
}

int main(void)
{
    card deck[52];
    int good=1;
    
    srand(time(NULL));
    
    filldeck(deck);
    
    printf("1회차 실행...\n");
    while(1)
    {
        suffle(deck);
        deal(deck);
        
        if(good==1)
        {
            if(straight(deck)==0)
            {
                prin(deck);
                printf("\nNot straight!\n");
            }
        }else{
            if(straight(deck)==1)
            {
                prin(deck);
                printf("\n%d회차 실행:straight!\n",good);
                break;
            }
        }
        good++;

    }
}
