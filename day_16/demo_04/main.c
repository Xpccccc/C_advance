#include <stdio.h>

//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
//奇数位保留，偶数位变为0只需要按位与（&）上01010101010101010101010101010101转成16进制就是：0x55555555
//偶数位保留，奇数位变为0只需要按位与（&）上10101010101010101010101010101010转成16进制就是：0xaaaaaaaa

#define EXCHANGE(n) (((n&0x55555555)<<1)+((n&0xaaaaaaaa)>>1))

int main() {
    int n = 10;
    printf("%d  ", EXCHANGE(n));
    return 0;
}