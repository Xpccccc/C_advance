#include <stdio.h>

//1、编写一个程序，输入 a、b、c 三个值，输出其中最大值。
int main() {
    int a, b, c = 0;
    int max = 0;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    printf("最大值>:%d", max);
    return 0;
}
