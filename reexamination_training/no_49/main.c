#include <stdio.h>

#define MAX(a, b, c) a = a>b?a:b;a = a>c?a:c;

//48、分别用函数和带参的宏，从三个数中找出最大的数。
int max(int a, int b, int c) {
    int max = 0;
    if (a > b)
        max = a;
    else
        max = b;
    if (max < c)
        max = c;
    return max;
}

int main() {
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    int ret2 = max(a, b, c);
    MAX(a, b, c);//最大值是a
    printf("%d %d\n", a, ret2);
    return 0;
}
