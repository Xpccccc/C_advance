#include "SList.h"

void TestSList1() {
    int n = 0;
    printf("请输入链表长度:");
    scanf("%d", &n);
    printf("\n请依次输入每个结点的值:");
    SLTNode *plist = NULL;//第一个节点，接下来需要先赋值
    for (int i = 0; i < n; ++i) {
        int x = 0;
        scanf("%d", &x);
        //创建新结点
        SLTNode *newnode = BuySListNode(x);
        //头插
        newnode->next = plist;
        plist = newnode;
    }
    SLTPrint(plist);

    SLTPushBack(plist, 10);
    SLTPushBack(plist, 20);
    SLTPushBack(plist, 30);
    SLTPrint(plist);
}

void TestSList2() {
    SLTNode *plist = NULL;//第一个节点，接下来需要先赋值

    //尾插
    SLTPushBack(&plist, 10);
    SLTPushBack(&plist, 20);
    SLTPushBack(&plist, 30);
    SLTPushBack(&plist, 40);
    SLTPushBack(&plist, 50);
    SLTPrint(plist);
}

void TestSList3() {
    SLTNode *plist = NULL;//第一个节点，接下来需要先赋值

    //头插
    SLTPushFront(&plist, 10);
    SLTPushFront(&plist, 20);
    SLTPushFront(&plist, 30);
    SLTPrint(plist);
}

void TestSList4() {
    SLTNode *plist = NULL;//第一个节点，接下来需要先赋值
    SLTPushBack(&plist, 10);
    SLTPushBack(&plist, 20);
    SLTPushBack(&plist, 30);
    SLTPushBack(&plist, 40);
    SLTPushBack(&plist, 50);
    SLTPrint(plist);

    //尾删
    SLTPopBack(&plist);
    SLTPopBack(&plist);
    SLTPopBack(&plist);
    SLTPopBack(&plist);
    SLTPopBack(&plist);
    SLTPopBack(&plist);
    SLTPrint(plist);
}

void TestSList5(){
    SLTNode *plist = NULL;//第一个节点，接下来需要先赋值
    SLTPushBack(&plist, 10);
    SLTPushBack(&plist, 20);
    SLTPushBack(&plist, 30);
    SLTPushBack(&plist, 40);
    SLTPushBack(&plist, 50);
    SLTPrint(plist);

    //头删
    SLTPopFront(&plist);
    SLTPopFront(&plist);
    SLTPopFront(&plist);
    SLTPopFront(&plist);
    SLTPrint(plist);

}

int main() {
//    TestSList1();
//    TestSList2();
//    TestSList3();
//    TestSList4();
    TestSList5();
    return 0;
}
