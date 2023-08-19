#include "Stack.h"

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

//栈
int main() {
    TestStack1();
    return 0;
}
