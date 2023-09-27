//
// Created by 徐鹏 on 2023/8/17.
//

#ifndef DEMO_01_STACK_H
#define DEMO_01_STACK_H

#endif //DEMO_01_STACK_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack {
    STDataType *data;
    int top;//栈顶
    int capacity;
} Stack;

//初始化栈
void STInit(Stack *ps);

//入栈
void STPush(Stack *ps, STDataType x);

//出栈
void STPop(Stack *ps);

//栈空
bool STEmpty(Stack *ps);

//栈顶元素
STDataType STTop(Stack *ps);

//栈深度
int STSize(Stack *ps);

//销毁栈
void STDestroy(Stack *ps);
