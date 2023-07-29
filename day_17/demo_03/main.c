#include "SeqList.h"

//顺序表
int main() {
    SL sl;
    SLInit(&sl);
    SLPushBack(&sl, 1);
    SLPushBack(&sl, 2);
    SLPushBack(&sl, 3);
    SLPushBack(&sl, 4);
    SLPushBack(&sl, 5);
    SLPushBack(&sl, 6);
    SLPrint(&sl);

    SLPopBack(&sl);
    SLPopBack(&sl);
    SLPrint(&sl);

    SLPushFront(&sl, 7);
    SLPushFront(&sl, 8);
    SLPushFront(&sl, 9);
    SLPrint(&sl);
    SLPopFront(&sl);
    SLPopFront(&sl);
    SLPrint(&sl);
    printf("%d \n", SeqListFind(&sl, 4));

    SeqListInsert(&sl, 3, 5);
    SLPrint(&sl);

    SeqListErase(&sl, 2);
    SLPrint(&sl);
    return 0;
}
