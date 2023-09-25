#include "Sort.h"

const int n = 10000000;

int *CreatData() {
    int *a = (int *) malloc(sizeof(int) * n);
    srand((unsigned int) time(0));
    for (int i = 0; i < n; ++i) {
        a[i] = rand() + i;
    }
    return a;
}


//排序算法
int main() {

    int arr[] = {1, 4, 6, 7, 9, 0, 4, 2, 5, 6, 777, 7, 8, 5, 4, 3, 7, 4, 78, 1};
////    InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
////    ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
////    BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
////    SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
////    HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
    QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int *a1 = CreatData();
    int *a2 = (int *) malloc(sizeof(int) * n);
    int *a3 = (int *) malloc(sizeof(int) * n);
    int *a4 = (int *) malloc(sizeof(int) * n);
    int *a5 = (int *) malloc(sizeof(int) * n);
    int *a6 = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        a1[i] = rand();
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
    }
    int start1 = clock();
    //InsertSort(a1, n);
    int end1 = clock();
    printf("InsertSort:%.3lf秒\n", (double) (end1 - start1) / CLOCKS_PER_SEC);

    int start2 = clock();
    ShellSort(a2, n);
    int end2 = clock();
    printf("ShellSort:%.3lf秒\n", (double) (end2 - start2) / CLOCKS_PER_SEC);

    int start3 = clock();
    //BubbleSort(a3, n);
    int end3 = clock();
    printf("BubbleSort:%.3lf秒\n", (double) (end3 - start3) / CLOCKS_PER_SEC);

    int start4 = clock();
    //SelectSort(a4, n);
    int end4 = clock();
    printf("SelectSort:%.3lf秒\n", (double) (end4 - start4) / CLOCKS_PER_SEC);

    int start5 = clock();
    HeapSort(a5, n);
    int end5 = clock();
    printf("HeapSort:%.3lf秒\n", (double) (end5 - start5) / CLOCKS_PER_SEC);

    int start6 = clock();
    QuickSort(a6, 0, n - 1);
    int end6 = clock();
    printf("QuickSort:%.3lf秒\n", (double) (end6 - start6) / CLOCKS_PER_SEC);

    return 0;
}
