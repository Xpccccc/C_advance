#include <stdio.h>

//洛谷：P1317 低洼地
int main() {
    int n = 0;
    int arr[10000] = {0};
    int count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n - 1; i++) {
        if ((arr[i - 1] > arr[i]) && (arr[i] < arr[i + 1])) {
            count++;
        } else if ((arr[i - 1] > arr[i]) && (arr[i] == arr[i + 1])) {
            for (int j = i + 1; j < n - 1; j++) {
                if (arr[j] > arr[i]) {
                    count++;
                    break;
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}