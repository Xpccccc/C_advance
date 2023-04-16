#include <stdio.h>
#include <string.h>
#include <assert.h>

void *my_memcpy(void *dest, const void *src, size_t num) {
    assert(dest && src);
    void *ret = dest;
    while (num--) {
        *(char *) dest = *(char *) src;
        dest = (char *) dest + 1;//每次拷贝一个字节
        src = (char *) src + 1;
    }
    return ret;
}

//memcpy的模拟实现
int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[5] = {0};
    my_memcpy(arr2, arr1, 20);//arr1拷贝20个字节到arr2
    for (int i = 0; i < 5; ++i) {
        printf("%d ", arr2[i]);
    }
    return 0;
}
