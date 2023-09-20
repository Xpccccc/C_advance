//
// Created by 徐鹏 on 2023/9/20.
//

#include "Sort.h"

//插入排序
void InsertSort(int *arr, int n) {

    for (int i = 0; i < n - 1; ++i) {
        //一趟
        int end = i;
        int tmp = arr[end + 1];
        while (end >= 0) {
            if (tmp < arr[end]) {
                arr[end + 1] = arr[end];
            } else {
                break;
            }
            --end;
        }
        arr[end + 1] = tmp;
    }
}

//希尔排序
void ShellSort(int *arr, int n) {
//    int gap = n;
//    while (gap > 1) {
//        gap = gap / 3 + 1;
//        for (int i = 0; i < n - gap; i += gap) {
//            int end = i;
//            int tmp = arr[end + gap];
//            while (end >= 0) {
//                if (tmp < arr[end]) {
//                    arr[end + gap] = arr[end];
//                } else {
//                    break;
//                }
//                end -= gap;
//            }
//            arr[end+gap] = tmp;
//        }
//    }

    int gap = n;
    while (gap > 1) {
        gap = gap / 3 + 1;
        //预排序
        for (int i = 0; i < n - gap; i++) {
            int end = i;
            int tmp = arr[end + gap];
            while (end >= 0) {
                if (tmp < arr[end]) {
                    arr[end + gap] = arr[end];
                } else {
                    break;
                }
                end -= gap;
            }
            arr[end + gap] = tmp;
        }
    }
}

void Swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//冒泡排序
void BubbleSort(int *arr, int n) {
    for (int j = 0; j < n; ++j) {
        int flag = 0;
        for (int i = 0; i < n - 1 - j; ++i) {
            if (arr[i + 1] < arr[i]) {
                flag = 1;
                Swap(&arr[i], &arr[i + 1]);
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

//选择排序
void SelectSort(int *arr, int n) {
    int mini = 0;
    int maxi = 0;
    int start = 0;
    int end = n - 1;
    while (start < end) {
        for (int i = start + 1; i <= end; ++i) {
            if (arr[i] > arr[maxi]) {
                maxi = i;
            }
            if (arr[i] < arr[mini]) {
                mini = i;
            }
        }
        Swap(&arr[mini], &arr[start]);
        //注意此时如果start刚好是最大值的话，就会把最大值换走了，也就是本来最大值在 0 位置，交换后换到其他位置了，所以判断一下
        if (start == maxi) {
            maxi = mini;//找到最大值的下标
        }
        Swap(&arr[maxi], &arr[end]);
        //向中间靠拢
        ++start;
        --end;
    }
}

void AdjustUp(int *arr, int child) {
    //调整当前child个元素的数组为堆，以便于对后面的的建堆
    int parent = (child - 1) / 2;
    while (child > 0) {
        if (arr[child] > arr[parent]) {
            Swap(&arr[parent], &arr[child]);
            //继续向上调整
            child = parent;
            parent = (child - 1) / 2;
        } else {
            break;
        }
    }
}

//向下调整
void AdjustDown(int *arr, int n, int parent) {
    int child = parent * 2 + 1;//假设这是最大那个孩子
    while (child < n) {
        if (child + 1 < n && arr[child + 1] > arr[child]) {
            child = child + 1;//找到最大的那个孩子
        }
        if (arr[child] > arr[parent]) {
            Swap(&arr[parent], &arr[child]);
            //继续向下调整
            parent = child;
            child = parent * 2 + 1;
        } else {
            break;
        }
    }
}

//堆排序
void HeapSort(int *arr, int n) {
    //建堆 - 升序建大堆
//    for (int i = 1; i < n; ++i) {
//        //向上调整 - 弊端，可能每个结点都需要向上调整 - 最下面元素个数最多，调整的次数也多 ，最上面元素个数少，调整的次数也少 O(nlogn)
//        AdjustUp(arr, i);
//    }
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
        //向下调整  -  最下面元素个数最多，但调整的次数少 ，最上面元素个数少，但调整的次数多  O(n)
        AdjustDown(arr, n, i);
    }

    //堆排序
    for (int i = n - 1; i >= 0; --i) {
        Swap(&arr[0], &arr[i]);//把最大的元素放到最后面，然后向下调整
        AdjustDown(arr, i, 0);//这里n是需要调整的元素个数
    }
}