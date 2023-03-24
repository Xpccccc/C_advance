#include <stdio.h>


//洛谷：P1089 [NOIP2004 提高组] 津津的储蓄计划
int main() {
    int arr[12] = {0};
    float sum = 0;
    int store = 0;
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }
    int flag = 0;
    for (int i = 0; i < 12; i++) {
        sum += ((store + 300 - arr[i]) / 100) * 100;
        store = (store + 300 - arr[i]) - (store + 300 - arr[i]) / 100 * 100;
        if (store < 0) {
            flag = 1;
            printf("%d\n", -(i + 1));
            break;
        }
    }
    if (0 == flag)
        printf("%d\n", store + (int) (sum * 1.2));
    return 0;
}