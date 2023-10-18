//
// Created by 徐鹏 on 2023/8/8.
//

#include "List.h"

//创建新结点
LTNode *BuyLTNode(LTDataType x) {
    LTNode *newhead = (LTNode *) malloc(sizeof(LTNode));
    if (newhead == NULL) {
        perror("malloc error!");
        exit(-1);
    }
    newhead->data = x;
    newhead->next = NULL;
    newhead->prev = NULL;
    return newhead;
}

//初始化循环双链表
LTNode *LTInit() {
    LTNode *phead = BuyLTNode(-1);
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

//打印循环双链表
void LTPrint(LTNode *phead) {
    assert(phead);
    LTNode *cur = phead->next;
    while (phead != cur) {
        printf("%d<=>", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

//双向链表尾插
void LTPushBack(LTNode *phead, LTDataType x) {
    assert(phead);
    LTNode *tail = phead->prev;
    LTNode *newnode = BuyLTNode(x);
    newnode->prev = tail;
    tail->next = newnode;

    newnode->next = phead;
    phead->prev = newnode;

}

// 双向链表尾删
void LTPopBack(LTNode *phead) {
    assert(phead);
    assert(phead->next != phead);//只有带头结点不用删
    LTNode *tail = phead->prev;
    LTNode *tailprev = tail->prev;
    free(tail);
    tailprev->next = phead;
    phead->prev = tailprev;
}

// 双向链表头插
void LTPushFront(LTNode *phead, LTDataType x) {
    assert(phead);
    LTNode *newnode = BuyLTNode(x);
    newnode->next = phead->next;
    phead->next->prev = newnode;
    phead->next = newnode;
    newnode->prev = phead;
}

// 双向链表头删
void LTPopFront(LTNode *phead) {
    assert(phead);
    assert(phead->next != phead);//空链表
    LTNode *tail = phead->next;
    phead->next = tail->next;
    tail->next->prev = phead;
    free(tail);
}

// 双向链表查找
LTNode *LTFind(LTNode *phead, LTDataType x) {
    assert(phead);
    LTNode *cur = phead->next;
    while (phead != cur) {
        if (cur->data == x) {
            return cur;
        }
        cur = cur->next;
    }
    //没找到
    return NULL;
}

// 双向链表在pos的前面进行插入
void LTInsert(LTNode *pos, LTDataType x) {
    assert(pos);
    LTNode *newhead = BuyLTNode(x);
    LTNode *posprev = pos->prev;
    newhead->next = pos;
    pos->prev = newhead;
    posprev->next = newhead;
    newhead->prev = posprev;
}

// 双向链表删除pos位置的节点
void LTErase(LTNode *pos) {
    assert(pos);
    assert(pos->next != pos);//确保链表非空
    LTNode *posprev = pos->prev;
    posprev->next = pos->next;
    pos->next->prev = posprev;
    free(pos);
}

// 双向链表销毁
void LTDestory(LTNode *phead) {
    //头删尾删都行
    //这里用头删
    while (phead->next != phead) {
        LTNode *tail = phead->next;
        phead->next = tail->next;
        tail->next->prev = phead;
        free(tail);
    }
    free(phead);
}