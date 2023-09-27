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
#include "Stack.h"

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

//快速排序 -- 递归
void QuickSort(int *arr, int begin, int end);

//快速排序 -- 非递归
void QuickSortNonR(int *arr, int begin, int end);

//归并排序 -- 递归方法
void MergeSort(int *arr, int begin, int end);

//归并排序 -- 非递归方法
void MergeSortNonR(int *arr, int begin, int end);

//计数排序
void CountSort(int *arr, int n);