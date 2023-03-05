#include <stdio.h>

//21、打印出杨辉三角的前十行
int main() {
    int arr[10][10] = {0};//初始化
    arr[0][0] = 1;//第一行
    arr[1][0] = 1;//第二行
    arr[1][1] = 1;
    //第三行往后
    //1
    //11
    //121
    //1331
    for (int i = 2; i < 10; i++) {
        for (int j = 0; j <= i; ++j) {//控制列数
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];//等于当前元素正上方的元素和正上方左边元素的和，最右边元素也等于1+0
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("Hello, World!\n");
    return 0;
}
