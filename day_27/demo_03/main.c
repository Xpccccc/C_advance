#include <stdio.h>

//WY49 数对
int main() {
    int n = 0, k = 0;
    long count = 0;
    scanf("%d%d", &n, &k);
    //x和y均不大于n
    for (int x = k; x <= n; ++x) {//x取值大于等于k
        //y的取值大于等于x+k;
        count += n - (x + k) + 1;
    }
    printf("%ld", count);
    return 0;
}