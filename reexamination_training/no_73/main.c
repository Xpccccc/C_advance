#include <stdio.h>
#include <tgmath.h>

//73、写一个函数，对一个16 位的二进制数驱除它的奇数位。
int main() {
    short n = 0;
    scanf("%hd", &n);
    short sum = 0;
    for (int i = 0; i < 16; i += 2) {
        sum += ((n >> i) & 1) * pow(2, i);
    }
    printf("%hd\n", sum);
    return 0;
}
