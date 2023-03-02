#include <stdio.h>

//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在
//要求：时间复杂度小于O(N);

int search(int(*arr)[5], int i, int x) {
    int left = 0;
    int right = 4;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x > (*(arr + i))[mid]) {  //(*(arr + i))表示第i行的地址
            left = mid + 1;
        } else if (x < (*(arr + i))[mid]) {
            right = mid - 1;
        } else {
            return 1;//找到了
        }
    }
    return 0;//没找到
}

int main() {
    int arr[3][5] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7};
    int input = 0;
    scanf("%d", &input);
    int i = 0;
    for (i = 0; i < 3; i++) {
        if (1 == search(arr, i, input)) {
            printf("存在\n");
            break;
        }
    }
    if (0 == search(arr, i,input))
        printf("不存在\n");
    return 0;
}
