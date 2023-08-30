//
// Created by 徐鹏 on 2023/8/20.
//

#include "Queue.h"

//初始化队列
void QueInit(Que *pq) {
    assert(pq);
    pq->head = pq->tail = NULL;
    pq->size = 0;
}

//销毁队列
void QueDestroy(Que *pq) {
    assert(pq);
    QNode *cur = pq->head;
    while (cur != NULL) {
        QNode *post_cur = cur->next;
        free(cur);
        cur = post_cur;
    }
    pq->head = pq->tail = NULL;
    pq->size = 0;
}

//判空
bool QueEmpty(Que *pq) {
    if (pq->head == NULL) {
        return true;
    } else {
        return false;
    }
}

//队长
int QueSize(Que *pq) {
    assert(pq);
    return pq->size;
}

//队头
QDatatype QueFront(Que *pq) {
    assert(pq);
    assert(!QueEmpty(pq));
    return pq->head->data;
}

//队尾
QDatatype QueBack(Que *pq) {
    assert(pq);
    assert(!QueEmpty(pq));
    return pq->tail->data;
}

//入队
void QuePush(Que *pq, QDatatype x) {
    assert(pq);
    QNode *newnode = (QNode *) malloc(sizeof(QNode));
    if (newnode == NULL) {
        perror("malloc error");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    if (pq->tail == NULL) {
        pq->head = pq->tail = newnode;
    } else {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
    pq->size++;
}

//出队
void QuePop(Que *pq) {
    assert(pq);
    assert(!QueEmpty(pq));
    if (pq->head->next == NULL) {
        //只有一个结点
        free(pq->head);
        pq->head = pq->tail = NULL;
    } else {
        QNode *post_head = pq->head->next;
        free(pq->head);
        pq->head = post_head;
    }
    pq->size--;
}