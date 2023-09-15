//
// Created by 徐鹏 on 2023/8/20.
//

#ifndef DEMO_01_QUEUE_H
#define DEMO_01_QUEUE_H

#endif //DEMO_01_QUEUE_H


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BTNode *QDatatype;//入栈的是指向当前结点的指针 这里不认typedef的BTNode

typedef struct QueueNode {
    QDatatype data;
    struct QueueNode *next;
} QNode;

typedef struct Queue {
    QNode *head;
    QNode *tail;
    int size;
} Que;


//初始化队列
void QueInit(Que *pq);

//判空
bool QueEmpty(Que *pq);

//销毁队列
void QueDestroy(Que *pq);

//队长
int QueSize(Que *pq);

//队头
QDatatype QueFront(Que *pq);

//队尾
QDatatype QueBack(Que *pq);

//入队
void QuePush(Que *pq, QDatatype x);

//出队
void QuePop(Que *pq);

