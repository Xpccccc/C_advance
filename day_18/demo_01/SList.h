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

// 单链表查找
SLTNode *SListFind(SLTNode *plist, SLTDataType x);

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SLTNode **pos, SLTDataType x);

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SLTNode *pos);

// 单链表的销毁
void SListDestroy(SLTNode **plist);
