//
// Created by 徐鹏 on 2023/9/11.
//

#ifndef DEMO_01_HEAP_H
#define DEMO_01_HEAP_H

#endif //DEMO_01_HEAP_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

typedef int HPDataType;

//堆
typedef struct heap {
    HPDataType *data;
    int size;
    int capacity;
} HP;

//初始化堆
void HeapInit(HP *php);

//对已有的数据建堆
void HeapInitArray(HP *php, int *a, int n);

//堆的销毁
void HeapDestroy(HP *php);

//打印堆数据
void HeapPrint(const HP *php);

//入堆
void HeapPush(HP *php, HPDataType x);

//出堆
void HeapPop(HP *php);

//堆顶元素
HPDataType HeapTop(const HP *php);

//对堆判空
bool HeapEmpty(const HP *php);

//向上调整堆
void AdjustUp(HPDataType *a, int child);

//向下调整堆
void AdjustDown(HPDataType *a, int n, int parent);

//交换两个数据元素
void Swap(HPDataType *a, HPDataType *b);