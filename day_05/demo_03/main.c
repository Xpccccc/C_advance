#include <stdio.h>

int Add(int x, int y) {
    return x + y;
}

int Sub(int x, int y) {
    return x - y;
}

int Mul(int x, int y) {
    return x * y;
}

int Div(int x, int y) {
    return x / y;
}

//函数指针
int main() {
    int (*pf[])(int ,int )={Add, Sub, Mul, Div};
    for (int i = 0; i < 4; ++i) {
        printf("%d ",pf[i](8,4));
    }
    return 0;
}
