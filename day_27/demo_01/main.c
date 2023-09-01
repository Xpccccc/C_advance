#include <stdio.h>
#include <stdlib.h>

//KS33 寻找奇数
//采用异或
int main() {
    int n = 0;
    int result = 0;
    scanf("%d", &n);
    int *num = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num[i]);
    }
    for (int i = 0; i < n; ++i) {
        result ^= num[i];//相同的元素异或等于0，1^2^1^2^3 = 3
    }
    printf("%d", result);
    return 0;
}