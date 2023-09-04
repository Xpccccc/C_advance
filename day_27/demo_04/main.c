/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param nums int整型一维数组 
 * @param numsLen int nums数组长度
 * @return int整型
 */

//NC107 寻找峰值
int findPeakElement(int *nums, int numsLen) {
    // write code here

    //先考虑边界
    if (nums[1] < nums[0]) {
        return 0;
    }
    if (nums[numsLen - 2] < nums[numsLen - 1]) {
        return numsLen - 1;
    }
    for (int i = 1; i < numsLen - 1; ++i) {
        if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1])
            return i;
    }
    return -1;//不存在
}