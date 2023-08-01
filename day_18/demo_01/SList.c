//
// Created by 徐鹏 on 2023/7/31.
//
#include "SList.h"

//打印链表

void SLTPrint(SLTNode *phead) {
    SLTNode *cur = phead;
    while (cur != NULL) {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

//创建新结点
SLTNode *BuySListNode(SLTDataType x) {
    SLTNode *newnode = (SLTNode *) malloc(sizeof(SLTNode));
    if (NULL == newnode) {
        perror("malloc error");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

//尾插
void SLTPushBack(SLTNode **pphead, SLTDataType x) {
    SLTNode *newnode = BuySListNode(x);//新结点
    if (NULL == *pphead) {
//        phead = newnode;//这里只会phead指向结点，因为phead是临时变量，出了函数就销毁了,所以一定要plist指向newnode
        // 改变结构体指针，所以要二级指针
        *pphead = newnode;//*phead就是plist
    } else {
        SLTNode *tail = *pphead;
        //找到表尾
        while (tail->next) {
            tail = tail->next;
        }
        //改变结构体，所以用结构体指针
        tail->next = newnode;
    }
}

//头插
void SLTPushFront(SLTNode **pphead, SLTDataType x) {
    SLTNode *newnode = BuySListNode(x);//新结点
    newnode->next = *pphead;
    *pphead = newnode;
}

//尾删
void SLTPopBack(SLTNode **pphead) {
    //空
    assert(*pphead);
    //一个结点
    if ((*pphead)->next == NULL) {
        free(*pphead);
        *pphead = NULL;
    } else {
        //一个结点以上
        SLTNode *tail = *pphead;
        SLTNode *tailpre = NULL;//tail前驱
        while (tail->next) {
            tailpre = tail;//保留前驱
            tail = tail->next;
        }
        free(tail);
        tailpre->next = NULL;

    }
}

//头删
void SLTPopFront(SLTNode **pphead) {
    //空
    assert(*pphead);
    //非空
    SLTNode *newhead = (*pphead)->next;
    free(*pphead);
    *pphead = newhead;
}

// 单链表查找
SLTNode *SListFind(SLTNode *plist, SLTDataType x) {
    assert(plist);
    SLTNode *retnode = plist;
    while (retnode->next) {
        if (retnode->data == x) {
            //找到了
            return retnode;
        }
        retnode = retnode->next;
    }
    //没找着
    return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SLTNode **pos, SLTDataType x) {
    SLTNode *newnode = BuySListNode(x);
    if (*pos == NULL) {
        *pos = newnode;
    } else {
        newnode->next = (*pos)->next;
        (*pos)->next = newnode;
    }

}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SLTNode *pos) {
    //保证一个以上的结点
    assert(pos->next);
//    //一个结点
//    if ((*pos)->next == NULL) {
//        free(*pos);
//        *pos = NULL;
//    } else {
//        //一个以上结点
//        SLTNode *q = (*pos)->next;
//        (*pos)->next = (*pos)->next->next;
//        free(q);
//        q = NULL;
//    }
    //一个以上结点
    SLTNode *q = pos->next;//防止找不到pos后面的结点
    pos->next = pos->next->next;
    free(q);
    q = NULL;
}

// 单链表的销毁
void SListDestroy(SLTNode **plist) {
    assert(*plist);
    while (*plist) {//头结点不为空
        //头删
        SLTPopFront(plist);
        //删到最后头结点为空
    }
}