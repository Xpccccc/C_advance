#include <stdio.h>

//洛谷：P1420 最长连号
int main() {
    int n = 0;
    int arr[10000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count = 1;
    int max = 1;
    for (int i = 0; i < n; i++) {
        if ((arr[i] + 1) == arr[i + 1]) {
            count++;
        } else {
            if (count > max)
                max = count;
            count = 1;
        }
    }
    printf("%d\n", max);
    return 0;
}