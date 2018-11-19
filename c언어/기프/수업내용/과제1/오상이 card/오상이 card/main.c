#include "card.h"

void filldeck(card *deck)
{
    int i;
    for (i = 0; i <= 51; i++)
    {
        deck[i].face = i % 13;
        deck[i].suit = i / 13;
        
    }
}
void shuffle(card *deck)
{
    int i, j;
    card temp;
    for (i = 0; i <= 51; i++)
    {
        j = rand() % 52;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
        
    }
}
void deal(card *deck, card *mine)
{
    int i;
    
    for (i = 0; i < count; i++)
    {
        mine[i].suit = deck[i].suit;
        mine[i].face = deck[i].face;
    }
}
void sorting(card *mine)
{
    int i, j;
    card temp;
    
    for (i = 0; i < count; i++)
    {
        for (j = i; j < count; j++)
        {
            if (mine[i].face > mine[j].face)//작은것을 앞으로 소팅
            {
                temp = mine[i];
                mine[i] = mine[j];
                mine[j] = temp;
            }
        }
    }
}
void cardprint(card *mine)
{
    int i;
    
    for (i = 0; i < count; i++)
    {
        printf(" %5s of %-8s", strface[mine[i].face], strsuit[mine[i].suit]);
        printf("\n");
    }
}
int choice(card *mine, card *straight)// 숫자가 똑같은 카드를 한번만 뽑아오기
{
    int i, j;
    int cnt = 0;//같은 숫자가 있으면 카운트를 올림
    int k = 0;//stragit 판별에 필요한 카드 숫자를 저장해줌.
    
    //card temp;
    
    for (i = 0; i < count; i++)
    {
        for (j = i; j < count; j++)
        {
            if (mine[i].face == mine[j].face)
            {
                cnt++;
            }
            if (cnt == 0)
            {
                straight[k++] = mine[i];
            }
        }
    }
    return k;
}



int straightchecking(card *straight,int k)
{
    int i,j;
    int cnt=0;
    
    for (i = 0; i < k; i++)
    {
        for (j = i + 1; j < k;)
        {
            if (straight[i].face != straight[j].face - 1)
            {
                cnt++;
                break;
            }
            else
                break;
        }
        
    }
    if (cnt >= k-5)
        return 1;//straight 아님
    else
        return 0;//straight 0
}



int main()
{
    card deck[52];
    card mine[count];
    card straight[count];
    int k=0;
    int chek;//return 값 저장
    int cnt=0;//제일 처음 한번은 출력해야함. straight 가 아니더라도 &횟수 측정
    
    srand((long)time(NULL));
    
    while(1)
    {
        filldeck(deck);
        shuffle(deck);
        deal(deck, mine);
        sorting(mine);
        if (cnt == 0)
        {
            cardprint(mine);
        }
        
        k=choice(mine,straight);
        
        if (k < 5)
        {
            if (cnt == 0)
            {
                printf("Not Straight\n");
            }
            cnt++;
            continue;
        }
        else
            chek=straightchecking(straight, k);
        
        if (chek == 0)
        {
            cnt++;
            break;
        }
        else
        {
            if (cnt == 0)
            {
                printf("Not Straight\n");
            }
            cnt++;
        }
    }
    
    cardprint(mine);
    printf("%d회차 시행 : Straight", cnt);
    
    return 0;
    
}
