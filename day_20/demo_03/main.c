#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    //每行第一个元素的值为n*n-n+1
    int start = n * n - n + 1;//第一个元素
    printf("%d", start);
    for (int i = 1; i < n; ++i) {
        printf("+%d", start + 2 * i);//后面n-1个元素
    }
    return 0;
}