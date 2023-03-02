#include <stdio.h>

//5、给定一个不多于 5 位的正整数，要求：① 求它是几位数；② 分别打印出每
//一位数字；③ 按逆序打印出各位数字。例如原数为 321，应输出 123。
int main() {
    int n = 0;
    int count = 0;
    scanf("%d", &n);
    while (n) {
        printf("%d", n % 10);
        n /= 10;
        count++;
    }
    printf("\n位数=%d\n", count);
    return 0;
}
