#include <stdio.h>

//44、输入两个整数，求他们相除的余数。用带参的宏来实现，编程序

#define MOD(a, b)  a=a%b;

int main() {
    int a, b = 0;
    scanf("%d %d", &a, &b);
    MOD(a, b);
    printf("%d\n", a);
    return 0;
}
