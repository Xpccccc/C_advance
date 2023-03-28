#include <stdio.h>

//洛谷：P1534 不高兴的津津（升级版）
int main() {
    int n = 0;
    int arr[3000][2] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int sum = 0;
    int unhappy = 0;
    for (int i = 0; i < n; i++) {
        sum += (arr[i][0] + arr[i][1]) - 8;
        unhappy += sum;
    }
    printf("%d\n", unhappy);
    return 0;
}
