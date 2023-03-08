#include <stdio.h>
#include <tgmath.h>

//33、写一个函数，使给定的一个二维数组（３×３）转置，即行列互换。
int main() {
    int arr[3][3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 3; ++i) {//转置
        for (int j = i; j < 3; ++j) {//j = i防止后边元素继续交换
            if (i != j) {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
