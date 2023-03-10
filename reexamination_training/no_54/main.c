#include <stdio.h>
#include <stdlib.h>

#define N 10
//53、有n个整数，使前面各数顺序向后移m个位置，最后m个数变成前面m个数，见图。
// 写一函数：实现以上功能，在主函数中输入n个数和输出调整后的n个数。

int *hy(int *arr, int m) {
    int *arr1 = (int *) malloc(sizeof(int) * N + m);//开辟N+m个空间的数组
    for (int i = 0; i < N; ++i) {
        //arr所有元素放到后移m个位置的arr1里
        arr1[i + m] = arr[i];
    }
    for (int i = 0; i < m; ++i) {
        //将arr1前面的m个元素用arr1后面的arr1的后面m个元素填充
        arr1[i] = arr1[N + i];
    }
    return arr1;
}

int main() {
    int arr[N] = {0};
    //输入N个数
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }
    int m = 0;
    //输入要后移的个数
    scanf("%d", &m);
    int *arr1 = hy(arr, m);
    for (int i = 0; i < N; ++i) {
        printf("%d ", arr1[i]);
    }
    return 0;
}
