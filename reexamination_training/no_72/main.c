#include <stdio.h>
#include <tgmath.h>

//72、编写一个函数getbits，从一个16 位的单元中取出某几位（即该几位保留原值，其余位为0）。
// 函数调用形式为：getbits(value,n1,n2)其中value 为该16 位单元中的数据值，n1 为欲取出的起始位，n2 为欲取出的结束位。

int getbits(short value, int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += ((value >> i) & 1) * pow(2, i);
    }
    return sum;
}

int main() {
    short value = 0;
    int n1 = 0;
    int n2 = 0;
    scanf("%hd %d %d", &value, &n1, &n2);
    int ret = getbits(value, n1, n2);
    printf("%d\n", ret);
    return 0;
}