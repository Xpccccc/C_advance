#include <stdio.h>
#include <string.h>

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 7};
    int arr2[] = {1, 3, 3, 4, 5, 6};
    int ret = memcmp(arr1, arr2, 21);//对比数组的前21个字节的每个字节的大小，在不相等的地方结束
    printf("%d\n", ret);//-1
    return 0;
}
