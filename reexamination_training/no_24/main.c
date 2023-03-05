#include <stdio.h>

#define N 3

//23、找出一个二维数组中的鞍点，即该位置上的元素在该行上最大，在该列上最小，也可能没有鞍点。
int main() {
    int arr[N][N] = {0};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (arr[i][j] < arr[i][k])//判断行
                    break;
            }
        }
    }
    printf("Hello, World!\n");
    return 0;
}
