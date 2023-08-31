#include <stdio.h>
#include <math.h>

//ZJ16 数列的和
int main() {
    double sum = 0.0;
    double n = 0;
    int m = 0;
    while (scanf("%lf%d", &n, &m) != EOF) {
        while (m--) {
            sum += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", sum);
        sum = 0.0;
    }
    return 0;
}