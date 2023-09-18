#include <stdio.h>

void insertSort(int *arr, int n) {

    for (int i = 0; i < n - 1; ++i) {
        //一趟
        int end = i;
        int tmp = arr[end + 1];
        while (end >= 0) {
            if (tmp < arr[end]) {
                arr[end + 1] = arr[end];
            } else {
                break;
            }
            --end;
        }
        arr[end + 1] = tmp;
    }
}

//直接插入排序
int main() {
    int arr[] = {1, 4, 6, 7, 9, 0, 4, 2, 5, 6, 777, 7, 8, 5, 4, 3, 7, 4, 78, 1};
    insertSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
