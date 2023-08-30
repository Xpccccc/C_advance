#include "Stack.h"
#include "Queue.h"

void TestStack1(){
    Stack st;
    STInit(&st);
    STPush(&st,1);
    STPush(&st,2);
    STPush(&st,1);
    STPush(&st,4);
    STPush(&st,5);
    while(!STEmpty(&st)){
        printf("%d", STTop(&st));
        STPop(&st);
    }
    STDestroy(&st);
}

void TestQue1(){
    Que q;
    QueInit(&q);
    QuePush(&q,1);
    QuePush(&q,2);
    QuePush(&q,3);
    QuePush(&q,4);
    while(!QueEmpty(&q)){
        printf("%d", QueFront(&q));
        QuePop(&q);
    }
    QueDestroy(&q);
}

//栈和队列
int main() {
//    TestStack1();
    TestQue1();
    return 0;
}
