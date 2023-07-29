//
// Created by 徐鹏 on 2023/7/29.
//
#include "SeqList.h"

//初始化顺序表
void SLInit(SL *sl) {
    assert(sl);
    //开辟空间
    sl->a = (SLDataType *) malloc(sizeof(SL) * INIT_SIZE);
    if (sl->a == NULL) {
        perror("malloc error");
        exit(-1);
    }
    sl->size = 0;
    sl->capacity = INIT_SIZE;
}

//打印
void SLPrint(const SL *sl) {
    assert(sl);
    for (int i = 0; i < sl->size; ++i) {
        printf("%d ", sl->a[i]);
    }
    printf("\n");
}

int CheckCapacity(SL *sl) {
    assert(sl);
    //满了要扩容
    if (sl->size == sl->capacity) {
        SLDataType *tmp = realloc(sl->a, 2 * sizeof(SL) * sl->capacity);
        if (tmp == NULL) {
            perror("realloc error");
            return -1;//没扩容
        }
        sl->a = tmp;
        sl->capacity *= 2;
        printf("扩容成功\n");
        return 0;//扩容
    }
    return 0;//不用扩容
}

//销毁顺序表
void SLDestroy(SL *sl) {
    assert(sl);
    sl->size = 0;
    sl->capacity = 0;
    free(sl->a);
    sl->a = NULL;
}

//表尾插入
void SLPushBack(SL *sl, SLDataType x) {
    assert(sl);
    if (0 == CheckCapacity(sl)) {
        sl->a[sl->size] = x;
        sl->size++;
    } else {
        //扩容失败
        printf("扩容失败\n");
    }

}

//从顺序表表尾删除
void SLPopBack(SL *sl) {
    assert(sl);
    assert(sl->size > 0);
    sl->size--;
}

//表头插入
void SLPushFront(SL *sl, SLDataType x) {
    assert(sl);
    //检查容量
    if (0 == CheckCapacity(sl)) {
        for (int i = sl->size - 1; i >= 0; --i) {
            //挪动数据
            sl->a[i + 1] = sl->a[i];
        }
        sl->a[0] = x;
        sl->size++;
    }
}

//从顺序表表头删除
void SLPopFront(SL *sl) {
    assert(sl);
    assert(sl->size > 0);
    for (int i = 0; i < sl->size - 1; ++i) {
        sl->a[i] = sl->a[i + 1];
    }
    sl->size--;
}

// 顺序表查找
int SeqListFind(const SL *sl, SLDataType x) {
    assert(sl);
    for (int i = 0; i < sl->size; ++i) {
        if (x == sl->a[i]) {
            return i;
        }
    }
    return -1;//没找到
}

// 顺序表在pos位置插入x
void SeqListInsert(SL *sl, int pos, SLDataType x) {
    assert(sl);
    //检查容量
    if (0 == CheckCapacity(sl)) {
        for (int i = sl->size - 1; i >= pos; --i) {
            //从pos位置开始往后移
            sl->a[i + 1] = sl->a[i];
        }
        sl->a[pos] = x;
        sl->size++;
    }
}

// 顺序表删除pos位置的值
void SeqListErase(SL *sl, int pos) {
    assert(sl);
    for (int i = pos; i < sl->size - 1; ++i) {
        sl->a[i] = sl->a[i + 1];
    }
    sl->size--;
}



