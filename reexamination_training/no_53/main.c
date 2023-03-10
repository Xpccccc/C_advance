#include <stdio.h>

//52、输入10个整数，将其中最小的数与第一个数对换，把最大的数与最后一个数对换。
// 写三个函数；①输入10个数；②进行处理；③输出10个数。

void sc(int *arr) {
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }
}

void sort(int *arr) {
    int max = 0;//记录最大值的位置
    int min = 0;//记录最小值的位置
    int i;
    for (i = 1; i < 10; ++i) {
        if (arr[i] > arr[max]) {//找出最大值的位置
            max = i;
        }
        if (arr[i] < arr[min]) {//找出最小值的位置
            min = i;
        }
    }
    int temp1 = arr[max];
    arr[max] = arr[9];
    arr[9] = temp1;
    int temp2 = arr[min];
    arr[min] = arr[0];
    arr[0] = temp2;
}

void print(int *arr) {
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[10] = {0};
    sc(arr);
    sort(arr);
    print(arr);
    return 0;
}
