#include <stdio.h>

//洛谷：P1075 [NOIP2012 普及组] 质因数分解
int main() {
    int arrange[7][2] = {0};
    int hour[7] = {0};
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &arrange[i][j]);
            hour[i] += arrange[i][j];
        }
    }
    int max = 0;
    int k = 0;
    for (int i = 0; i < 7; i++) {
        if (hour[i] > max && hour[i] > 8) {
            max = hour[i];
            k = i + 1;
        }
    }
    printf("%d\n", k);
    return 0;
}