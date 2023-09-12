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
    //向上调整时间复杂度O(nlogn)
//    for (int i = 1; i < n; ++i) {
//        AdjustUp(a, i);
//    }

    //向下调整时间复杂度O(n),从后往前建堆(所有子树都是小根堆（大根堆）才能调整堆结构)
    for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
        AdjustDown(a, n, i);
    }
    //把最小的值和最后一个位置交换，然后对前面的n-1个元素向下调整
    int end = n - 1;
    while (end > 0) {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);//因为这里第二个参数是当前要调整的堆的元素个数，即刚好是end
        --end;
    }
}

//int main() {
//    int a[] = {60, 100, 70, 32, 50, 60};
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//    HeapSort(a, sizeof(a) / sizeof(a[0]));
//    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
//        printf("%d ", a[i]);
//    }
//    return 0;
//}

void CreateData() {
    //造数据
    int n = 10000000;
    srand(time(0));
    FILE *pf = fopen("data.txt", "w");
    if (pf == NULL) {
        perror("fopen error");
        return;
    }
    for (int i = 0; i < n; ++i) {
        int x = rand() % 100000;
        fprintf(pf, "%d\n", x);
    }
    fclose(pf);
    pf = NULL;
}

//并不一定排序，只是会取出前k个最大（最小）的数
void PrintTopK(const char *filename, int k) {
    //TopK的数据
    FILE *pf = fopen(filename, "r");
    if (pf == NULL) {
        perror("fopen error");
        return;
    }
    int *top = (int *) malloc(sizeof(int) * k);//存储最大（最小）的前k个数据
    for (int i = 0; i < k; ++i) {
        fscanf(pf, "%d", &top[i]);
    }
    //此时pf指针指向了第k+1个元素
    //向下调整时间复杂度O(n),建堆,前k个数
    for (int i = (k - 1 - 1) / 2; i >= 0; --i) {
        AdjustDown(top, k, i);
    }
    //将剩余的n-k的元素与堆顶对比
    int x = 0;
    //此时pf指针指向了第k+1个元素，即可以取后面的n-k个元素
    while (fscanf(pf, "%d", &x) != EOF) {
        //大于堆顶元素则替换堆顶，然后向下调整
        if (x > top[0]) {
            top[0] = x;
            //并不一定排序，只是会取出前k个最大（最小）的数
            AdjustDown(top, k, 0);
        }
    }
    //打印
    for (int i = 0; i < k; ++i) {
        printf("%d ", top[i]);
    }
    fclose(pf);
    pf = NULL;
}

int main() {
    //CreateData();
    PrintTopK("data.txt", 8);
    return 0;
}
