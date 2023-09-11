//
// Created by 徐鹏 on 2023/9/11.
//
#include "Heap.h"

//初始化堆
void HeapInit(HP *php) {
    assert(php);
    php->data = NULL;
    php->size = php->capacity = 0;
}

//对已有的数据建堆
void HeapInitArray(HP *php, int *a, int n) {
    assert(php);
    assert(a);
    //用数组初始化建堆
    HPDataType *tmp = (HPDataType *) malloc(sizeof(HPDataType) * n);
    if (NULL == tmp) {
        perror("malloc error");
        exit(-1);
    }
    php->size = php->capacity = n;
    php->data = tmp;
    memcpy(php->data, a, sizeof(HPDataType) * n);
    //建堆
    for (int i = 1; i < n; ++i) {
        AdjustUp(php->data, i);
    }
}

//堆的销毁
void HeapDestroy(HP *php) {
    assert(php);
    free(php->data);
    php->data = NULL;
    php->size = php->capacity = 0;
}

//打印堆数据
void HeapPrint(const HP *php) {
    assert(php);
    for (int i = 0; i < php->size; ++i) {
        printf("%d ", php->data[i]);
    }
    printf("\n");
}

//交换两个数据元素
void Swap(HPDataType *a, HPDataType *b) {
    HPDataType tmp = *a;
    *a = *b;
    *b = tmp;
}

//向上调整堆
void AdjustUp(HPDataType *a, int child) {
    int parent = (child - 1) / 2;//孩子和双亲比较，孩子小就向上调整（小根堆）
    while (child > 0) {
        if (a[child] < a[parent]) {
            //交换
            Swap(&a[child], &a[parent]);
            //继续向上调整
            child = parent;
            parent = (child - 1) / 2;
        } else {
            break;//已经符合小根堆
        }
    }
}

//入堆
void HeapPush(HP *php, HPDataType x) {
    assert(php);
    //判满
    if (php->size == php->capacity) {
        int newCapacity = php->size == php->capacity == 0 ? 4 : 2 * php->capacity;
        HPDataType *tmp = (HPDataType *) realloc(php->data, sizeof(int) * newCapacity);
        if (tmp == NULL) {
            perror("realloc error");
            exit(-1);
        }
        php->data = tmp;
        php->capacity = newCapacity;
    }
    php->data[php->size] = x;
    php->size++;
    //向上调整
    AdjustUp(php->data, php->size - 1);
}

//向下调整堆
void AdjustDown(HPDataType *a, int n, int parent) {
    int child = parent * 2 + 1;//假设这是那个值更小的孩子(数组从0开始，所以是左孩子)
    while (child < n) {
        if (child + 1 < n && a[child] > a[child + 1]) {//child + 1 < n防止越界
            child++;//右孩子更小
        }
        if (a[child] < a[parent]) {
            Swap(&a[child], &a[parent]);
            parent = child;//继续向下调整
            child = parent * 2 + 1;
        } else {
            break;
        }
    }
}

//出堆
void HeapPop(HP *php) {
    assert(php);
    assert(php->size > 0);
    Swap(&php->data[0], &php->data[php->size - 1]);
    --php->size;//移除最后一个元素，也就是最小的元素
    AdjustDown(php->data, php->size, 0);
}

//堆顶元素
HPDataType HeapTop(const HP *php) {
    assert(php);
    assert(php->size > 0);
    return php->data[0];
}
//对堆判空
bool HeapEmpty(const HP *php) {
    assert(php);
    return php->size == 0;
}