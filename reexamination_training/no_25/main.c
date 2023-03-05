#include <stdio.h>

//24、有15个数按由小到大顺序存放在一个数组中，输入一个数，要求用折半查找
//法找出该数组中第几个元素的值。如果该数不在数组中，则打印出"无此数"
int main() {
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = 0;
    scanf("%d", &n);
    int left = 0;
    int right = 14;
    int mid;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (n > arr[mid]) {//往右边找
            left = mid + 1;
        } else if (n < arr[mid]) {//往左边找
            right = mid - 1;
        } else {
            printf("找到了，下标为%d", mid);
            break;
        }
    }
    if (left > right)
        printf("无此数\n");
    return 0;
}
