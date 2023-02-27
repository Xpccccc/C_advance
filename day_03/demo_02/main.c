#include <stdio.h>

int main() {
    int n = 9;
    //00000000 00000000 00000000 1001
    float *pFloat = (float *) &n;
    //浮点数IEEE754
    //(-1)^0 * 2^-127 *1.0000000 00000000 1001    == 0
    printf("n的值为：%d\n", n);//9
    printf("*pFloat的值为：%f\n", *pFloat);//0.000000

    *pFloat = 9.0;
    //1001.0 -二进制  -> 1.001 * 2^3 -> E = 3+127
    //0  10000010 00100000000000000000000  --  IEEE754
    printf("n的值为：%d\n", n);//1091567616
    printf("*pFloat的值为：%f\n", *pFloat);//9.000000

    return 0;
}
