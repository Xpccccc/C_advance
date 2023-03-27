#include <stdio.h>

//洛谷：P1421 小玉买文具
int main() {
    int a, b = 0;
    scanf("%d %d", &a, &b);
    printf("%d\n", (a * 10 + b) / 19);
    return 0;
}