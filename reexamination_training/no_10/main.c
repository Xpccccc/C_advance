#include <stdio.h>

//9、一个数如果恰好等于它的因子之和，这个数就称为"完数"。
// 例如，6的因子为1、2、3，而6=1+2+3，因此6是"完数"。
// 编程序找出1000之内的所有完数，并按下面格式输出其因子：6 its factors are 1、2、3
int main() {
    int sum = 0;
    for (int i = 1; i <= 1000; i++) {
        sum = 0;
        for (int j = 1; j < i; ++j) {
            if (i % j == 0)
                sum += j;
        }
        if (i == sum)
            printf("%d ", i);
    }
    return 0;
}
