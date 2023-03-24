#include <stdio.h>

//洛谷：P1150 Peter 的烟
int main() {
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    int sum = n;
    while (n / k >= 1) {
        sum += n / k;
        n = n / k + (n % k);
    }
    printf("%d\n", sum);
    return 0;
}