#include "Header.h"



int scanYear(){
    int ret;
    
    while(1){
        printf("연식을 입력하세요(0000):");
        scanf("%d", &ret);
        
        if(ret > 2016 || ret < 1900)
            printf("잘못 입력하였습니다. 다시 입력하세요. \n");
        else
            break;
    }
    return ret;
}



int scanMoney(){
    int ret;
    
    while(1){
        printf("가격을 입력하세요(만원):");
        scanf("%d", &ret);
        
        if(ret < 100)
            printf("잘못 입력하였습니다. 다시 입력하세요. \n");
        else
            break;
    }
    return ret;
}



void prinCar(car car){
    printf("차종:%s  연식:%d  가격:%d  회사:%s \n", car.carname, car.year, car.price, car.company);
}




int IfSmallerMoney(car car, int findmoney){
    int ret = 0;
    
    if(car.price <= findmoney)
        ret++;
    
    return ret;
}



int IfNextYear(car car, int findyear){
    int ret = 0;
    
    if(car.year >= findyear)
        ret++;
    
    return ret;
}



int oneCar(car car, int findyear, int findmoney){
    if(IfSmallerMoney(car, findmoney))
        if(IfNextYear(car, findyear)){
            prinCar(car);
            return 1;
    }
    return 0;
}


void findCar(car car[], int findyear, int findmoney){
    int i, howmany = 0;
    
    printf("%d년 이후 출시되었으며 %d만원 이하의 차는... \n", findyear, findmoney);
    
    for(i=0; i<MAX; i++)
        howmany += oneCar(car[i], findyear, findmoney);
    
    
    if(!howmany)
        printf("조건을 만족하는 차량이 없습니다. \n");
}



int main(void){
    car car[5] =
    {
        {"SOLAR", 2000, 2000, "HYUNDA"},
        {"AVANT", 1995, 1500, "HYUNDA"},
        {"MOHAV", 2010, 3000, "KIAA"},
        {"PASAT", 2005, 2500, "VOLKS"},
        {"OPIRUSA", 2015, 3500, "KIAA"}
    };
    
    int findyear, findmoney;
    
    findyear = scanYear();
    findmoney = scanMoney();
    
    findCar(car, findyear, findmoney);
    
}
