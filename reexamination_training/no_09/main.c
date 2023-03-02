#include <stdio.h>
#include <tgmath.h>

//9、打印出100~1000所有"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该本身。
// 例如：153 是一个水仙花数，因为 153=1^3+5^3+3^3。

int is_Narcissistic_number(int n) {
    int count = 0;
    int temp = n;
    int sum = 0;
    while (temp) {
        temp /= 10;
        count++;
    }
    temp = n;
    while (temp) {
        sum += pow(temp % 10, count);
        temp /= 10;
    }
    if (sum == n)
        return 1;
    else
        return 0;
}

int main() {
    for (int i = 100; i <= 1000; i++) {
        if (1 == is_Narcissistic_number(i))
            printf("%d ", i);
    }
    return 0;
}
