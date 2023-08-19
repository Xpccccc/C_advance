
//20. 有效的括号
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

bool isValid(char *s) {
    //左括号入栈，右括号出栈
    Stack st;
    STInit(&st);
    while (*s) {
        if (*s == '(' || *s == '[' || *s == '{') {
            STPush(&st, *s);
        } else {
            //此时栈空了.数量不匹配
            if (STEmpty(&st)) {
                return false;
            }
            char topVal = STTop(&st);
            STPop(&st);
            if (*s == ')' && topVal != '(' || *s == ']' && topVal != '[' || *s == '}' && topVal != '{') {
                return false;
            }
        }
        s++;
    }
    bool ret = STEmpty(&st);//如果栈里面还有数据，则不匹配
    STDestroy(&st);
    return ret;
}