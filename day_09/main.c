#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 50

//栈的顺序结构
typedef struct {
    int data[MAXSIZE];
    int top;//栈顶指针
} SqStack;

//初始化
void InitStack(SqStack *S) {
    S->top = -1;
}

//判断栈空
bool StackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    else
        return false;
}

//进栈
bool Push(SqStack *S, int x) {
    if (S->top == MAXSIZE - 1)
        return false;//栈已满
    S->data[++S->top] = x;
    return true;
}

//出栈
bool Pop(SqStack *S, int *x) {
    if (S->top == -1)
        return false;//栈已空
    *x = S->data[S->top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack S, int *x) {
    if (S.top == -1)
        return false;//栈已空
    *x = S.data[S.top];
    return true;
}

int main() {
    printf("Hello, World!\n");
    return 0;
}
