#include <stdio.h>

//43、定义一个带参的宏，使两个参数的值互换，并写出程序，输入两个数作为使
//用宏时的实参。输出已交换后的两个值。

#define SWAP(a, b) t=a;a=b;b=t;

int main() {
    int a = 0;
    int b = 0;
    int t = 0;
    scanf("%d %d", &a, &b);
    SWAP(a, b);
    printf("%d %d\n", a, b);
    return 0;
}
