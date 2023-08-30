
//485. 最大连续 1 的个数
int findMaxConsecutiveOnes(int *nums, int numsSize) {
    int max = 1;//记录最大连续1的个数
    int count = 1;//记录当前最大连续1的个数
    if (numsSize == 1)
        return nums[0];
    int flag = 0;//记录全0的标志
    for (int i = 0, j = 1; j < numsSize; j++) {
        if (nums[i] == nums[j]) {
            if (nums[i] == 1) {
                count++;
                if (count > max) {
                    max = count;
                }
            }
            //nums[i] = 0不用管       
        } else {
            flag = 1;//有不相等的肯定有1
            count = 1;//从当前位置重新算最大连续1个个数
            i = j;
        }
    }
    if (flag == 0 && nums[0] != 1) {
        return 0;
    }//nums[0] != 1防止全1的情况
    return max;
}