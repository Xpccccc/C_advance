#include <stdio.h>

//序列中删除指定数字
int main() {
    int n = 0;
    int x = 0;
    int arr[50] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    //数组里找x
    int j = 0;
    int k = 0;//记录要删除的元素个数
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == x) {
            j = i;//记录和i相等的元素位置
            for (; j < n; ++j) {
                if (x == arr[j]) {//相等则记录当前需要删除的元素个数
                    k++;
                } else {
                    arr[i] = arr[j];
                    i++;//i指针后移，以便下一次填入后面不等于x的元素
                }
            }
            break;
        }
    }
    for (int i = 0; i < n - k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}