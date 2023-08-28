typedef int QDatatype;

typedef struct QueueNode {
    QDatatype data;
    struct QueueNode *next;
} QNode;

typedef struct Queue {
    QNode *head;
    QNode *tail;
    int size;
} Que;

//初始化队列
void QueInit(Que *pq) {
    assert(pq);
    pq->head = pq->tail = NULL;
    pq->size = 0;
}

//销毁队列
void QueDestroy(Que *pq) {
    assert(pq);
    QNode *cur = pq->head;
    while (cur != NULL) {
        QNode *post_cur = cur->next;
        free(cur);
        cur = post_cur;
    }
    pq->head = pq->tail = NULL;
    pq->size = 0;
}

//判空
bool QueEmpty(Que *pq) {
    if (pq->head == NULL) {
        return true;
    } else {
        return false;
    }
}

//队长
int QueSize(Que *pq) {
    assert(pq);
    return pq->size;
}

//队头
QDatatype QueFront(Que *pq) {
    assert(pq);
    assert(!QueEmpty(pq));
    return pq->head->data;
}

//队尾
QDatatype QueBack(Que *pq) {
    assert(pq);
    assert(!QueEmpty(pq));
    return pq->tail->data;
}

//入队
void QuePush(Que *pq, QDatatype x) {
    assert(pq);
    QNode *newnode = (QNode *) malloc(sizeof(QNode));
    if (newnode == NULL) {
        perror("malloc error");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    if (pq->tail == NULL) {
        pq->head = pq->tail = newnode;
    } else {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
    pq->size++;
}

//出队
void QuePop(Que *pq) {
    assert(pq);
    assert(!QueEmpty(pq));
    if (pq->head->next == NULL) {
        //只有一个结点
        free(pq->head);
        pq->head = pq->tail = NULL;
    } else {
        QNode *post_head = pq->head->next;
        free(pq->head);
        pq->head = post_head;
    }
    pq->size--;
}


//225. 用队列实现栈

typedef struct {
    Que q1;
    Que q2;
} MyStack;


MyStack *myStackCreate() {
    MyStack *pst = (MyStack *) malloc(sizeof(MyStack));
    if (pst == NULL) {
        perror("malloc error!");
        exit(-1);
    }
    //初始化两个队列
    QueInit(&pst->q1);
    QueInit(&pst->q2);
    return pst;
}


void myStackPush(MyStack *obj, int x) {
    //入栈找队列不为空的那个
    if (!QueEmpty(&obj->q1)) {
        QuePush(&obj->q1, x);//入队
    } else {
        QuePush(&obj->q2, x);//入队
    }
}

int myStackPop(MyStack *obj) {
    //先将不为空的队列里面的size-1个元素放到为空的队列里面，然后pop当前队列
    Que *empty = &obj->q1;//记录当前空队列
    Que *nonEmpty = &obj->q2;//记录当前非空队列
    if (!QueEmpty(empty)) {
        //obj->q1队列非空
        empty = &obj->q2;
        nonEmpty = &obj->q1;
    }
    //将不为空的队列里面的size-1个元素放到为空的队列里面
    while (QueSize(nonEmpty) > 1) {
        //空队列开始入队
        QuePush(empty, QueFront(nonEmpty));
        QuePop(nonEmpty);
    }
    int top = QueFront(nonEmpty);// 取栈顶元素
    QuePop(nonEmpty);//将队列置空
    return top;
}

int myStackTop(MyStack *obj) {
    //取非空队列的tail元素
    if (!QueEmpty(&obj->q1)) {
        return QueBack(&obj->q1);
    } else {
        return QueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack *obj) {
    return QueEmpty(&obj->q1) && QueEmpty(&obj->q2);
}

void myStackFree(MyStack *obj) {
    QueDestroy(&obj->q1);
    QueDestroy(&obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/