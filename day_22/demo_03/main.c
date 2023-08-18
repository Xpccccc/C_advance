/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//349. 两个数组的交集
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    *returnSize = 0;
    //定义两个数组
    int *arr1 = (int *) malloc(sizeof(int) * 1001);
    memset(arr1, 0, sizeof(int) * 1001);
    int *arr2 = (int *) malloc(sizeof(int) * 1001);
    memset(arr2, 0, sizeof(int) * 1001);
    int *ret = (int *) malloc(sizeof(int) * 1001);
    memset(ret, 0, sizeof(int) * 1001);
    for (int i = 0; i < nums1Size; ++i) {
        arr1[nums1[i]] = 1;//标记
    }
    for (int i = 0; i < nums2Size; ++i) {
        arr2[nums2[i]] = 1;//标记
    }
    for (int i = 0, j = 0; i < 1001; ++i) {
        if (arr1[i] == arr2[i] && arr1[i] == 1) {
            ret[j++] = i;
            (*returnSize)++;
        }
    }
    return ret;
}