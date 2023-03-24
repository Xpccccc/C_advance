#include <stdio.h>

//洛谷：P1116 车厢重组
int main() {
    int arr[10000] = {0};
    int n = 0;
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
                count++;
            }
        }
        if (0 == flag)
            break;
    }
    printf("%d\n", count);
    return 0;
}