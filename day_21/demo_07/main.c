
//JZ53 数字在升序数组中出现的次数
int GetNumberOfK(int *nums, int numsLen, int k) {
    // write code here
    if (numsLen == 0) {
        return 0;
    }
    if (numsLen == 1) {
        if (nums[0] == k) {
            return 1;
        } else {
            return 0;
        }
    }
    int count = 0;
    for (int i = 0; i < numsLen - 1; ++i) {
        if (nums[i] == k) {
            count++;
            if (nums[i] != nums[i + 1]) {
                break;
            } else {
                //如果当前位置的值等于下一个位置的值，后移两步
                count++;
                ++i;//for里面也有++i,也就是后移两步；
            }
        }
    }
    return count;
}