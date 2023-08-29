#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//448. 找到所有数组中消失的数字
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize) {
    *returnSize = 0;
    int *ret = (int *) malloc(sizeof(int) * (numsSize));
    int *bucket = (int *) malloc(sizeof(int) * (numsSize + 1));
    memset(bucket, 0, (numsSize + 1) * sizeof(int));
//    for(int i=0; i<=numsSize; ++i){
//        bucket[i] = 0;
//    }
    for (int i = 0; i < numsSize; ++i) {
        bucket[nums[i]] = 1;
    }
    for (int i = 1; i <= numsSize; ++i) {
        if (0 == bucket[i]) {
            ret[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return ret;
}

int main() {
    int num[8] = {4, 3, 2, 7, 8, 2, 3, 1};
    int returnSize = 0;
    findDisappearedNumbers(num, 8, &returnSize);
    return 0;
}
