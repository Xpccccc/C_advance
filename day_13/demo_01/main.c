#include <stdio.h>

//指针运算、数据在内存中的布局
int main() {
    int a[5][5];
    int (*p)[4];
    p = a;

    printf("%p %d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//0xfffffffffffffffc -4
    return 0;
}
