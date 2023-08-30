#include <stdio.h>

int isPerfectNum(int n) {
    int sum = 0;//记录n的因子和
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    if (n == sum)
        return 1;
    else
        return 0;;
}

//HJ56 完全数计算
int main() {
    int n = 0;
    int count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        if (1 == isPerfectNum(i))
            count++;
    }
    printf("%d", count);
    return 0;
}