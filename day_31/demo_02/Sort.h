//
// Created by 徐鹏 on 2023/9/20.
//

#ifndef DEMO_02_SORT_H
#define DEMO_02_SORT_H

#endif //DEMO_02_SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>

//插入排序
void InsertSort(int *arr, int n);

//希尔排序
void ShellSort(int *arr, int n);

//冒泡排序
void BubbleSort(int *arr, int n);

//选择排序
void SelectSort(int *arr, int n);

//堆排序
void HeapSort(int *arr, int n);

//快速排序
void QuickSort(int *arr, int begin,int end);