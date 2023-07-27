#include <stdio.h>


int missingNumber(int *nums, int numberSize) {
    //数组中数值为  0-n
    int x = 0;
    for (int i = 0; i <= numberSize; ++i) {
        x ^= i;//相当于 x = 0^0^1^2^3.....
    }
    for (int i = 0; i < numberSize; ++i) {
        x ^= nums[i];//相当于 x = 0^0^1^2^3.....^num[0]^num[1]^num[2]...
        //其中出现过两次的数值异或为0，最后只剩下只出现一次的数值
    }
    return x;
}

//消失的数字--异或算法
int main() {
    int arr[11] = {0,1, 2, 3, 4, 5, 6, 7, 8, 10, 11};
    int ret = missingNumber(arr, 11);
    printf("%d\n", ret);
    return 0;
}
