#include <stdio.h>

//HJ11 数字颠倒
int main() {
    int n = 0;
    scanf("%d", &n);
    int num = n;
    int bit = 0;//n的位数
    if (n == 0)
        printf("%d", 0);
    while (num) {
        num /= 10;
        bit++;
    }
    num = n;//重置num
    int i = 0;
    while (i < bit) {
        printf("%d", num % 10);
        num /= 10;
        i++;
    }
    return 0;
}