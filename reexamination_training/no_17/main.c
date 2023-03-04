#include <stdio.h>

//16、用筛法求100之内的素数。
int main() {
    int arr[100] = {0};// 0表示是素数
    for (int i = 2; i < 100; ++i) {
        for (int j = i * 2; j < 100; j += i) {
            arr[j] = 1;//不是素数
        }
    }
    //其余是元素为0的就是素数
    for (int i = 0; i < 100; ++i) {
        if(arr[i] == 0)
            printf("%d ",i);
    }
    return 0;
}
