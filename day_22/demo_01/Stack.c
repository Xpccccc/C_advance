//
// Created by 徐鹏 on 2023/8/17.
//

#include "Stack.h"

//初始化栈
void STInit(Stack *ps) {
    assert(ps);
    ps->data = NULL;
    ps->capacity = 0;
    ps->top = 0;//指向栈顶的下一个位置
}

//入栈
void STPush(Stack *ps, STDataType x) {
    assert(ps);
    if (ps->top == ps->capacity) {
        //扩容
        int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType *temp = (STDataType *) realloc(ps->data, sizeof(STDataType) * newCapacity);
        if (temp == NULL) {
            perror("realloc error!");
            exit(-1);
        }
        ps->data = temp;
        ps->capacity = newCapacity;
    }
    ps->data[ps->top] = x;//入栈
    ps->top++;
}

//栈深度
int STSize(Stack *ps) {
    assert(ps);
    return ps->top;
}

//出栈
void STPop(Stack *ps) {
    assert(ps);
    //空
    assert(ps->top > 0);
    --ps->top;
}

//栈顶元素
STDataType STTop(Stack *ps) {
    assert(ps);
    assert(ps->top > 0);
    return ps->data[ps->top-1];
}

//栈空
bool STEmpty(Stack *ps) {
    assert(ps);
    if (ps->top == 0) {
        return true;
    } else {
        return false;
    }
}

//销毁栈
void STDestroy(Stack *ps) {
    assert(ps);
    free(ps->data);
    ps->data = NULL;
    ps->capacity = ps->top = 0;
}