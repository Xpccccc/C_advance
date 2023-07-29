//
// Created by 徐鹏 on 2023/7/29.
//

#ifndef DEMO_03_SEQLIST_H
#define DEMO_03_SEQLIST_H

#endif //DEMO_03_SEQLIST_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


#define INIT_SIZE 4

//#define N 100
//typedef int SLDataType ;
//
//静态顺序表
//struct SeqList{
//    int a[N];
//    SLDataType size;
//};

//动态顺序表
typedef int SLDataType ;
typedef struct SeqList{
    SLDataType* a;
    int size;
    int capacity;
}SL;

//初始化顺序表
void SLInit(SL* sl);
//销毁顺序表
void SLDestroy(SL* sl);
//表尾插入
void SLPushBack(SL* sl,SLDataType x);
//从顺序表表尾删除
void SLPopBack(SL* sl);
//表头插入
void SLPushFront(SL* sl,SLDataType x);
//从顺序表表头删除
void SLPopFront(SL* sl);
//打印
void SLPrint(const SL* sl);

// 顺序表查找
int SeqListFind(const SL* sl, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SL* sl, int pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SL* sl, int pos);