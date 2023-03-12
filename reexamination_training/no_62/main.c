#include <stdio.h>

//61、编写一个函数getbits，从一个16 位的单元中取出某几位（即该几位保留原值，其余位为0）。
// 函数调用形式为：getbits(value,n1,n2)其中value为该16 位单元中的数据值，n1 为欲取出的起始位，n2为欲取出的结束位

void getbits(int value, int start, int end) {
    for (short i = start; i <= end; ++i) {
        printf("%d ", (value >> i) & 1);
    }
}

int main() {
    short value, n1, n2 = 0;
    scanf("%hd %hd %hd", &value, &n1, &n2);
    getbits(value, n1, n2);
    return 0;
}
