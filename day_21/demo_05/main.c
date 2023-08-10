/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//645. 错误的集合
int *findErrorNums(int *nums, int numsSize, int *returnSize) {
    //定义一个n个元素的数组
    int *arr = (int *) malloc(sizeof(int) * 10001);
    for (int i = 0; i <= numsSize; i++) {
        arr[i] = 0;//初始化
    }
    int *ret = (int *) malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++) {
        arr[nums[i]] += 1;//重复的元素会加两次，缺的元素一次不加
    }
    for (int i = 1; i <= numsSize; i++) {
        if (arr[i] == 2) {
            ret[0] = i;
        }
        if (arr[i] == 0) {
            ret[1] = i;
        }
    }
    *returnSize = 2;
    return ret;
}