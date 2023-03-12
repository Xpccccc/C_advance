#include <stdio.h>

//62、已有一个已排好的数组今输入一个数要求按原来排序的规律将它插入数组中。
int main() {
    int arr[11] = {1, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < 10; ++i) {
        if (n < arr[i]) {
            for (int j = 9; j >= i; --j) {
                arr[j + 1] = arr[j];
            }
            arr[i] = n;
            break;
        }
    }
    for (int i = 0; i < 11; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
