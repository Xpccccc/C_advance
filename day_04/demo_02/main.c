#include <stdio.h>

void print(int(*arr)[5], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d ", *(*(arr + i) + j)); //即*(*(&arr1+i)+j)，其中&arr1+i，表示第i行的首地址
            //printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

//二维数组，数组指针用法
int main() {
    int arr[3][5] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 6, 3, 4, 5, 6, 7};
    //     1,2,3,4,5  --- arr1
    //     2,3,4,5,6  --- arr2
    //     3,4,5,6,7  --- arr3
    //整个arr数组的地址就是arr1数组的地址，即&arr1,用指针接收就是 int (*p)[5] = &arr1;
    print(arr, 3, 5);
    return 0;
}
