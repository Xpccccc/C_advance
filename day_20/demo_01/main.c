#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *printNumbers(int n, int *returnSize) {
    // write code here
    //创建10^n个元素的空间
    int *ret = (int *) malloc(sizeof(int) * pow(10, n));
    //输出10^n - 1个数
    for (int i = 0; i < pow(10, n) - 1; ++i) {
        //循环pow(10, n) - 1次
        ret[i] = i + 1;//从1开始，到pow(10, n) - 1
    }
    *returnSize = pow(10, n) - 1;//数组长度
    return ret;
}

//JZ17 打印从1到最大的n位数
int main() {
    int returnSize = 0;
    int *nums = 0;
    nums = printNumbers(5, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", nums[i]);
    }
    return 0;
}