#include <stdio.h>

//41、用递归方法求n阶勒让德多项式的值递归公式为：
//      {1,n=0
//Pn(x)={x,n=1
//      {((2n-1)*x-pn-1(x)-(n-1)*pn-2(x))/n, n>=1

float Pn(float n, int x) {
    if (0 == n)
        return 1;
    if (1 == n)
        return x;
    return ((2 * n - 1) * x - Pn(n - 1, x) - (n - 1) * Pn(n - 2, x)) / n;
}

int main() {
    int x = 0;
    float n = 0.0;
    scanf("%f %d", &n, &x);
    float ret = Pn(n, x);
    printf("%.2f\n", ret);
    return 0;
}
