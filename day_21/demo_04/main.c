#include <stdio.h>

//JZ11 旋转数组的最小数字
int minNumberInRotateArray(int *nums, int numsLen) {
    // write code here
    //冒泡排序
    for (int i = 0; i < numsLen - 1; ++i) {
        int flag = 1;//标志位
        for (int j = 0; j < numsLen - 1 - i; ++j) {//继续从下一个位置开始
            if (nums[j] > nums[j + 1]) {
                flag = 0;//说明有交换
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
        //如果有一躺没有交换，则直接结束排序（已经排序好）
        if (1 == flag)
            break;
    }
    return nums[0];
}

int main() {
    int nums[] = {3, 4, 5, 1, 2};
    int numsLen = 5;
    int ret = minNumberInRotateArray(nums, numsLen);
    printf("%d", ret);
    return 0;
}
