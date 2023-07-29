#include <stdio.h>


void reverse(int *nums, int left, int right) {
    while (left < right) {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }
}

void rotate(int *nums, int numsSize, int k) {
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}

//旋转数组
int main() {
    int num[] = {1, 2, 3, 4, 5, 6, 7};
    rotate(num, 7, 5);

    return 0;
}
