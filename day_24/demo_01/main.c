#include <printf.h>
#include <stdlib.h>
#include <tgmath.h>

//728. 自除数

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int is_selfDividingNumbers(int n) {
    int num = n;
    int bit = 0;//记录当前n的位数
    while (num) {
        num /= 10;
        bit++;
    }
    bit--;//减1方便后面pow
    num = n;//重置num
    while (bit != -1) {
        int cur = num / (int) pow(10, bit);
        num = num % (int) pow(10, bit);
        bit--;
        if (cur == 0) {//带0的都不行
            return 0;
        }
        if (n % cur != 0) {//看n能不能整除cur
            return 0;//不是
        }
    }
    return 1;//是
}

int *selfDividingNumbers(int left, int right, int *returnSize) {
    *returnSize = 0;
    int *ret = (int *) malloc(sizeof(int) * 10002);
    int j = 0;
    for (int i = left; i <= right; i++) {
        if (is_selfDividingNumbers(i) == 1) {
            ret[j++] = i;
            (*returnSize)++;
        }
    }
    return ret;
}

int main() {
    int a = 22;
    int returnSize = 0;
    int *ret = selfDividingNumbers(1, 22, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", ret[i]);
    }
    return 0;
}