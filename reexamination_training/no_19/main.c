#include <stdio.h>

//18、求一个3×3矩阵对角线元素之和
int main() {
    int arr[3][3] = {0};
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j || (i + j == 2 && i != 1))//主副对角线
                sum += arr[i][j];
        }
    }
    printf("%d\n", sum);
    return 0;
}
