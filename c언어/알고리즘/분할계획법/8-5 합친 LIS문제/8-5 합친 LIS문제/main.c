#include <stdio.h>

#define MAX 100


int buffer[MAX];




void bufferToLargestPartOFArr(int largestpart_Arr[], int whatelement){
    int i;
    
    for(i=0; i<=whatelement; i++)
        largestpart_Arr[i] = buffer[i];
}


int checkInc(int whatelement){
    int i, j, ret = 1;
    
    for(i = 0, j = i+1; i<whatelement; i++, j++){
        if(buffer[i] > buffer[j]){
            ret = 0;
            break;
        }
    }
    return ret;
}


int checkAlreadyPicked(int elementnum, int num){
    int i, ret=0;
    
    if (elementnum == 0) return ret;
    
    for(i=0; i < elementnum; i++)
        if(num == buffer[i]) ret ++;
    
    return ret;
}


void IfwhatelementEqualElementNum(int largestpart_Arr[], int whatelement, int part_arrlenght){
    if(checkInc(whatelement)){
        bufferToLargestPartOFArr(largestpart_Arr, whatelement);
    }
}


void pickElement(int arr[], int largestpart_Arr[], int arrlenght, int elementnum, int start, int part_arrlenght){
    int i;
    
    for(i = start; i < arrlenght-1; i++){
        if(checkAlreadyPicked(elementnum, arr[i]) == 0){
            buffer[elementnum] = arr[i];
            
            if(elementnum == part_arrlenght){
                IfwhatelementEqualElementNum(largestpart_Arr, elementnum, arrlenght);
                return;
            }
            
            pickElement(arr, largestpart_Arr, arrlenght, elementnum+1, start+1, part_arrlenght);
            
        }
    }
}


int smallestElement(int arr[], int elementNum){
    int i, min=99999;
    
    for(i=0; i<elementNum; i++){
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}


void findPartOfArrIFelementNum(int arr[], int largestpart_Arr[], int part_arrlenght, int arrlenght){
    if(part_arrlenght == 0){
        buffer[part_arrlenght] = smallestElement(arr, part_arrlenght);
    }else{
        pickElement(arr, largestpart_Arr, arrlenght, 0, 0, part_arrlenght);
    }
}


void findLargestPartOfArr(int arr[], int largestpart_Arr[], int arrlenght){
    int i;
    
    for(i=0; i<arrlenght; i++)
        findPartOfArrIFelementNum(arr, largestpart_Arr, i, arrlenght);
}


void scanArr(int arrlenght, int arr[]){
    int i;
    
    for(i=0; i<arrlenght; i++){
        printf("수열의 원소를 입력하세요: ");
        scanf("%d", &arr[i]);
    }
}


int scanArrLenght(int ArrLenght){
    while(1){
        printf("수열의 길이를 입력하세요. \n");
        scanf("%d", &ArrLenght);
        
        if(ArrLenght >= 1 && ArrLenght <= 100) break;
        else printf("다시 입력하세요. \n");
    }
    return ArrLenght;
}



int scanCase(int C){
    while(1){
        printf("케이스의 수를 입력하세요(1~50): ");
        scanf("%d",&C);
        
        if(C >= 1 && C <= 50) break;
        else printf("다시 입력하세요. \n");
    }
    return C;
}


int main(void){
    int C, Alenght, Blenght;
    int arrA[MAX]={0}, arrB[MAX]={0}, largestpart_A[MAX]={0}, largestpart_B[MAX]={0}, arrsum[MAX]={0};
    
    
    C = scanCase(C);
    Alenght = scanArrLenght(Alenght);
    Blenght = scanArrLenght(Blenght);
    
    scanArr(Alenght, arrA);
    scanArr(Blenght, arrB);
    
    
    
    
    
}
