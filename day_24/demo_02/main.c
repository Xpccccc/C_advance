
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//238. 除自身以外数组的乘积
int *productExceptSelf(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    int *ret = (int *) malloc(sizeof(int) * numsSize);
    int left = 1;
    int right = 1;
    for (int i = 0; i < numsSize; ++i) {
        ret[i] = 1;
    }
    //以i为分界线，left记录当前i左边的乘积，right记录i右边的乘积，以便于++i的乘积
    for (int i = 0; i < numsSize; ++i) {
        ret[i] *= left;//这里i进行到一半以后，ret[i]就等于目前的right了,相当于ret[i]分成两步计算
        left *= nums[i];//相当于i左边乘积 乘以 i右边乘积

        //这里i进行到一半以后，ret[numsSize-1-i]就等于目前的left了,相当于ret[i]分成两步计算
        ret[numsSize - 1 - i] *= right;//相当于i右边乘积 乘以 i左边乘积
        right *= nums[numsSize - 1 - i];
    }
    return ret;
}