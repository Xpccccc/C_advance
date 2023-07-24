#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int *Find_single(int arr[], int size) {
    int *ret = (int *) malloc(sizeof(int) * 2);//返回的数组
    //冒泡排序
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    //排序结束
    int count = 0;
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] != arr[i + 1]) {//前后不相等就是前面的为单个
            if (i == size - 2) {//到末尾了
                ret[0] = arr[size - 2];
                ret[1] = arr[size - 1];
                return ret;
            } else {
                ret[count++] = arr[i];
            }
        } else {//前后相等则跳2个
            i++;
        }
    }
    return ret;
}

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//编写一个函数找出这两个只出现一次的数字。
int main() {
    int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 9,7,9,7,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *ret = Find_single(arr, size);
    for (int i = 0; i < 2; ++i) {
        printf("%d ", ret[i]);
    }
    return 0;
}
