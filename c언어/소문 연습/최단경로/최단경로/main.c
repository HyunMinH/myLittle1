#include <stdio.h>


//함수 원형
void scan();
void findShortestPath(int curNode, int curDistance);
void saveShortestPath(int curDistance);
int canWeGo( int curNode, int nextNode);
int isIntheStack(int nextNode);
void push(int nextNode);
void pop();
void printMinInformation();


//전역변수: 전역변수란 이 파일에서 어느 함수에서든 사용할 수 있는 변수!
// 사실 별로 좋은 건 아니지만 이해를 돕기 위하여 사용~!!
int graph[10][10];      //0이면 가는 길이 없는 것이고 양수이면 그까지 가는데에 거리
int stack[10];   //path를 스택에 쌓아둠
int top;      //stack의 top
int minDistance;   //현재까지의 최소 거리
int minPath[10];      //현재까지의 저장해둔 최소거리 경로



int main(void) {
    scan();
    minDistance = 9999;
    top = -1;
    findShortestPath(0, 0);
    printMinInformation();
}



void scan() {
    //2차원 배열에 graph정보 입력
    int i, j;
    printf("graph 정보를 입력하세요.\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}


void findShortestPath(int curNode, int curDistance)
{
    //최단경로 찾기
    int i;
    
    push(curNode);      //경로 저장
    
    //curNode == 9이면 우리가 원하는 목적지에 도달했음
    if (curNode == 9) {
        if (curDistance < minDistance)   saveShortestPath(curDistance);
        return;
    }
    
    //갈수 있는 경로이면 curNode가 i인 재귀함수로 들어감.
    for (i = 0; i < 10; i++) {
        if (canWeGo(curNode, i)) {
            findShortestPath(i, curDistance + graph[curNode][i]);
            pop(i);   //위에 재귀함수에서 빠져나왔으니 stack에서 정보를 하나 pop함
        }
    }
}

void saveShortestPath(int curDistance)
{
    //stack에 있는 경로를 minPath에 저장
    int i;
    for (i = 0; i <= top; i++)
        minPath[i] = stack[i];
    minDistance = curDistance;
}


int canWeGo(int curNode, int nextNode)
{
    if (graph[curNode][nextNode] > 0 && !(isIntheStack(nextNode)) && curNode != nextNode)
        return 1;
    else
        return 0;
}


int isIntheStack(int nextNode)
{
    int i;
    for (i = 0; i <= top; i++)
        if (stack[i] == nextNode)
            return 1;
    return 0;
}


void printMinInformation()
{
    int i;
    printf("minDistance: %d \npath: ", minDistance);
    for (i = 0; i < 10; i++) {
        printf("%d  ", minPath[i]);
        if (minPath[i] == 9)   break;
    }
    printf("\n");
}

void push(int nextNode)
{
    //경로 하나를 stack에다가 저장
    top = top + 1;
    stack[top] = nextNode;
}

void pop()
{
    top = top - 1;
}
