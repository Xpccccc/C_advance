#include <stdio.h>

//19、已有一个已排好的数组今输入一个数要求按原来排序的规律将它插入数组中。
int main() {
    int arr[11] = {1, 3, 5, 8, 9, 23, 34, 55, 66, 77};
    int len = 10;//有效数组长度
    int n = 0;
    scanf("%d", &n);
    //从前往后比
    int i;
    for (i = 0; i < len; ++i) {
        if (n < arr[i]) {
            break;
        }
    }
    len++;
    for (int j = len-2; j >= i; --j) {//从i位置往后的元素后移一个位置
        arr[j + 1] = arr[j];
    }
    arr[i] = n;//插入元素
    for (int j = 0; j < len; ++j) {
        printf("%d ", arr[j]);
    }
    return 0;
}
