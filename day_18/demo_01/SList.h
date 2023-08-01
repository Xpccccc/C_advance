//
// Created by 徐鹏 on 2023/7/31.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#ifndef DEMO_01_SLIST_H
#define DEMO_01_SLIST_H

#endif //DEMO_01_SLIST_H

typedef int SLTDataType;

typedef struct SListNode {
    SLTDataType data;
    struct SListNode *next;
} SLTNode;

//打印链表
void SLTPrint(SLTNode *phead);

//创建新结点
SLTNode *BuySListNode(SLTDataType x);

//尾插
void SLTPushBack(SLTNode **pphead, SLTDataType x);

//尾删
void SLTPopBack(SLTNode **pphead);

//头插
void SLTPushFront(SLTNode **pphead, SLTDataType x);

//头删
void SLTPopFront(SLTNode **pphead);