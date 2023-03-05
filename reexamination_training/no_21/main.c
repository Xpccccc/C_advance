#include <stdio.h>

//20、将一个数组的值按逆序重新存放。例如，原来顺序为：8，6，5，4，1。要求
//改为：1，4，5，6，8。
int main() {
    int arr[5]={8,6,5,4,1};
    for (int i = 0; i < 5/2; ++i) {
        int temp = arr[i];
        arr[i]= arr[4-i];
        arr[4-i] = temp;
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d ",arr[i]);
    }
    return 0;
}
