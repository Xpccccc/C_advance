#include <stdio.h>

//37、写一函数，输入一个四位数字，要求输出这四个数字字符，但每两个数字间空格。如输入1990，应输出"1_9_9_0"。

void print(const int n) {
    int m = n;
    int x = 1000;
    int count = 0;//记录打印的次数
    while (x) {
        printf("%d", m / x);
        m = m % x;//取余数，相当于拿掉目前最高位
        x /= 10;//以便下次对m取余数
        count++;
        if (count < 4)
            printf("_");
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    print(n);
    return 0;
}
