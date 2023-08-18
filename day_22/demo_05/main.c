
//724. 寻找数组的中心下标
int pivotIndex(int *nums, int numsSize) {
    //先求数组总和，然后看前i个数的和乘以2加上当前i位置的值是否等于总和
    int sum = 0;
    int part_sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] + part_sum * 2 == sum) {
            return i;
        } else {
            part_sum += nums[i];

        }
    }
    //不存在
    return -1;
}