#include <stdio.h>

//用选择法对10个整数从小到大排序。
int main() {
    int arr[10] = {0};
    //输入
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = i+1; j < 10; ++j) {
            if (arr[i] > arr[j]) {//每次选一个最小的元素放在i的位置上
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
