#include <stdio.h>

//30、写两个函数，分别求两个整数的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果
// 两个整数由键盘输入。

int greatest_common_div(int a, int b) {
    int c = 0;
    while (a % b) {//辗转相除法
        c = a % b;
        a = b;
        b = c;
    }
    return b;//最大公约数
}

int least_common_mul(int a, int b) {
    int num = a * b;//a与b的乘积
    int c = 0;
    while (a % b) {//辗转相除法
        c = a % b;
        a = b;
        b = c;
    }
    return num / b;//最小公倍数
}

int main() {
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);
    int ret1 = greatest_common_div(a, b);//最大公约数
    int ret2 = least_common_mul(a, b);//最小公倍数
    printf("最大公约数=%d 最小公倍数=%d", ret1, ret2);
    return 0;
}
