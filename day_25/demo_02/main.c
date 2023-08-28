typedef int STDataType;

typedef struct Stack {
    STDataType *data;
    int top;//栈顶
    int capacity;
} Stack;

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
    return ps->data[ps->top - 1];
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


//232. 用栈实现队列
typedef struct {
    Stack pushst;//用来入栈
    Stack popst;//用来出栈
} MyQueue;


MyQueue *myQueueCreate() {
    MyQueue *pq = (MyQueue *) malloc(sizeof(MyQueue));
    if (pq == NULL) {
        perror("malloc error");
        exit(-1);
    }
    STInit(&pq->pushst);//初始化
    STInit(&pq->popst);//初始化
    return pq;
}

void myQueuePush(MyQueue *obj, int x) {
    STPush(&obj->pushst, x);
}

int myQueuePeek(MyQueue *obj) {
    //popst为空不能直接push
    if (STEmpty(&obj->popst)) {
        //pushst倒数据到popst
        while (!STEmpty(&obj->pushst)) {
            STPush(&obj->popst, STTop(&obj->pushst));
            STPop(&obj->pushst);
        }
    }
    return STTop(&obj->popst);
}

int myQueuePop(MyQueue *obj) {
    int front = myQueuePeek(obj);
    STPop(&obj->popst);
    return front;
}

bool myQueueEmpty(MyQueue *obj) {
    return STEmpty(&obj->popst) && STEmpty(&obj->pushst);
}

void myQueueFree(MyQueue *obj) {
    STDestroy(&obj->popst);
    STDestroy(&obj->pushst);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/