#include <stdio.h>

//洛谷：P1152 欢乐的跳
int main() {
    int n = 0;
    int arr[1000] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] - arr[i + 1] > 0 ? arr[i] - arr[i + 1] : arr[i + 1] - arr[i]) >= n) {
            flag = 1;
            break;
        }
    }
    if (0 == flag)
        printf("Jolly\n");
    else
        printf("Not jolly\n");
    return 0;
}