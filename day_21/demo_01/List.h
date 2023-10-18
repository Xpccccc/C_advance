//
// Created by 徐鹏 on 2023/8/8.
//

#ifndef DEMO_01_LIST_H
#define DEMO_01_LIST_H

#endif //DEMO_01_LIST_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

//带头循环双链表

typedef int LTDataType;

typedef struct LTNode {
    struct LTNode *next;
    struct LTNode *prev;
    LTDataType data;
} LTNode;


//初始化循环双链表，创建返回链表的头结点
LTNode *LTInit();

//打印循环双链表
void LTPrint(LTNode *phead);

//创建新结点
LTNode *BuyLTNode(LTDataType x);

//双向链表尾插
void LTPushBack(LTNode *phead, LTDataType x);

// 双向链表尾删
void LTPopBack(LTNode *phead);

// 双向链表头插
void LTPushFront(LTNode *phead, LTDataType x);

// 双向链表头删
void LTPopFront(LTNode *phead);

// 双向链表查找
LTNode *LTFind(LTNode *phead, LTDataType x);

// 双向链表在pos的前面进行插入
void LTInsert(LTNode *pos, LTDataType x);

// 双向链表删除pos位置的节点
void LTErase(LTNode *pos);

// 双向链表销毁
void LTDestory(LTNode *phead);