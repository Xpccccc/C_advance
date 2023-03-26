#include <stdio.h>

//洛谷：P1319 压缩技术
int main() {
    int n = 0;
    int arr[200] = {0};
    scanf("%d", &n);
    int i = 0;
    int sum = n * n;
    while (1) {
        scanf("%d", &arr[i]);
        sum -= arr[i];
        i++;
        if (sum == 0)
            break;
    }
    int num = 0;
    for (int j = 0; j < i; j++) {
        for (int k = 0; k < arr[j]; k++) {
            if (j % 2 == 0) {
                printf("%d", 0);
                num++;
            } else {
                printf("%d", 1);
                num++;
            }
            if (num % n == 0)
                printf("\n");
        }
    }
    return 0;
}