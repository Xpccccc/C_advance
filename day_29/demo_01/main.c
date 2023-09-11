#include "Heap.h"

//int main() {
//    int a[] = {60, 100, 70, 32, 50, 60};
//    HP hp;
//    HeapInit(&hp);
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
//        HeapPush(&hp, a[i]);
//    }
//    HeapPrint(&hp);
//    while (!HeapEmpty(&hp)) {
//        printf("%d ", HeapTop(&hp));
//        HeapPop(&hp);
//    }
//    printf("\n");
//    HeapDestroy(&hp);
//    return 0;
//}

//void HeapSort(int *a, int n) {
//    //建堆浪费空间
//    HP hp;
//    HeapInit(&hp);
//    for (int i = 0; i < n; ++i) {
//        HeapPush(&hp, a[i]);
//    }
//    int i = 0;
//    while (!HeapEmpty(&hp)) {
//        a[i++] = HeapTop(&hp);
//        HeapPop(&hp);
//    }
//    HeapDestroy(&hp);
//}

void HeapSort(int *a, int n) {
    //建堆
    //升序建大根堆
    //降序建小根堆
    for (int i = 1; i < n; ++i) {
        AdjustUp(a, i);
    }
    //把最小的值和最后一个位置交换，然后对前面的n-1个元素向下调整
    int end = n - 1;
    while (end > 0) {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);//因为这里第二个参数是当前要调整的堆的元素个数，即刚好是end
        --end;
    }
}

int main() {
    int a[] = {60, 100, 70, 32, 50, 60};
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    HeapSort(a, sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}
