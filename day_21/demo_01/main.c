#include "List.h"

void TestLT1() {
    LTNode *plist = LTInit();

    // 双向链表尾插
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPushBack(plist, 40);
    LTPushBack(plist, 50);
    LTPrint(plist);
}

void TestLT2() {
    LTNode *plist = LTInit();
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPushBack(plist, 40);
    LTPushBack(plist, 50);
    LTPrint(plist);

    // 双向链表尾删
    LTPopBack(plist);
    LTPopBack(plist);
    LTPopBack(plist);
    LTPrint(plist);
}

void TestLT3() {
    LTNode *plist = LTInit();
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPushBack(plist, 40);
    LTPushBack(plist, 50);
    LTPrint(plist);

    // 双向链表头插
    LTPushFront(plist, 1);
    LTPushFront(plist, 2);
    LTPushFront(plist, 3);
    LTPrint(plist);
}

void TestLT4() {
    LTNode *plist = LTInit();
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPushBack(plist, 40);
    LTPushBack(plist, 50);
    LTPrint(plist);

    // 双向链表头插
    LTPushFront(plist, 1);
    LTPushFront(plist, 2);
    LTPushFront(plist, 3);
    LTPrint(plist);


    // 双向链表头删
    LTPopFront(plist);
    LTPopFront(plist);
    LTPrint(plist);

}

void TestLT5() {
    LTNode *plist = LTInit();
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPushBack(plist, 40);
    LTPushBack(plist, 50);
    LTPrint(plist);

    // 双向链表头插
    LTPushFront(plist, 1);
    LTPushFront(plist, 2);
    LTPushFront(plist, 3);
    LTPrint(plist);


    // 双向链表头删
    LTPopFront(plist);
    LTPopFront(plist);
    LTPrint(plist);

    // 双向链表查找
    LTNode *ret = LTFind(plist, 1);
    printf("%p", ret);

}

void TestLT6() {
    LTNode *plist = LTInit();
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPushBack(plist, 40);
    LTPushBack(plist, 50);
    LTPrint(plist);

    // 双向链表头插
    LTPushFront(plist, 1);
    LTPushFront(plist, 2);
    LTPushFront(plist, 3);
    LTPrint(plist);


    // 双向链表头删
    LTPopFront(plist);
    LTPopFront(plist);
    LTPrint(plist);

    // 双向链表查找
    LTNode *ret = LTFind(plist, 1);
    // 双向链表在pos的前面进行插入
    LTInsert(ret, 3);
    LTPrint(plist);

}


void TestLT7() {
    LTNode *plist = LTInit();
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPushBack(plist, 40);
    LTPushBack(plist, 50);
    LTPrint(plist);

    // 双向链表头插
    LTPushFront(plist, 1);
    LTPushFront(plist, 2);
    LTPushFront(plist, 3);
    LTPrint(plist);


    // 双向链表头删
    LTPopFront(plist);
    LTPopFront(plist);
    LTPrint(plist);

    // 双向链表查找
    LTNode *ret = LTFind(plist, 1);
    // 双向链表删除pos位置的节点
    LTErase(ret);
    LTPrint(plist);

}

void TestLT8() {
    LTNode *plist = LTInit();
    LTPushBack(plist, 10);
    LTPushBack(plist, 20);
    LTPushBack(plist, 30);
    LTPushBack(plist, 40);
    LTPushBack(plist, 50);
    LTPrint(plist);

    // 双向链表头插
    LTPushFront(plist, 1);
    LTPushFront(plist, 2);
    LTPushFront(plist, 3);
    LTPrint(plist);


    // 双向链表头删
    LTPopFront(plist);
    LTPopFront(plist);
    LTPrint(plist);

    // 双向链表销毁
    LTDestory(plist);
    LTPrint(plist);

}

//循环双链表
int main() {
//    TestLT1();
//    TestLT2();
//    TestLT3();
//    TestLT4();
//    TestLT5();
//    TestLT6();
//    TestLT7();
    TestLT8();
    return 0;
}
