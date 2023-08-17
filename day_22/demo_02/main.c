
//747. 至少是其他数字两倍的最大数
int dominantIndex(int *nums, int numsSize) {
    int index = 0;//最大值的下标
    int max = nums[0];
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > max) {
            max = nums[i];
            index = i;//找到最大值下标
        }
    }
    //判断最大值是不是其他元素的2倍
    for (int i = 0; i < numsSize; ++i) {
        if (i != index) {
            if (nums[index] < 2 * nums[i]) {
                return -1;
            }
        }
    }
    return index;
}