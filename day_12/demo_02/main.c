#include<stdio.h>

//洛谷：P1422 小玉家的电费
int main() {
    double a1 = 150 * 0.4463;
    double a2 = a1 + (400 - 150) * 0.4663;
    int n = 0;
    scanf("%d", &n);
    if (n <= 150) {
        printf("%.1f\n", n * 0.4463);
    } else if (n <= 400) {
        printf("%.1f\n", a1 + (n - 150) * 0.4663);
    } else {
        printf("%.1f\n", a2 + (n - 400) * 0.5663);
    }
    return 0;
}