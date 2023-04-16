#include <stdio.h>
#include <string.h>

int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[5] = {0};
    // memcpy(arr1+2, arr1, 20)在内存重叠的时候，使用memcpy可能出现意想不到的效果
    memmove(arr1 + 2, arr1, 20);//操作后变为1 2 1 2 3 4 5 8 9 10
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr1[i]);
    }
    return 0;
}
