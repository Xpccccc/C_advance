/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//912. 排序数组

//希尔排序
void ShellSort(int *arr, int n) {
    int gap = n;
    while (gap > 1) {
        gap = gap / 3 + 1;
        //预排序
        for (int i = 0; i < n - gap; i++) {
            int end = i;
            int tmp = arr[end + gap];
            while (end >= 0) {
                if (tmp < arr[end]) {
                    arr[end + gap] = arr[end];
                } else {
                    break;
                }
                end -= gap;
            }
            arr[end + gap] = tmp;
        }
    }
}

int *sortArray(int *nums, int numsSize, int *returnSize) {
    ShellSort(nums, numsSize);
    *returnSize = numsSize;
    return nums;
}