#include <stdio.h>
#include <assert.h>

void *my_memmove(void *dest, const void *src, size_t num) {
    assert(dest && src);
    void *ret = dest;
    //分情况讨论,源地址和目的地址大小关系
    if (dest < ret) {
        //前->后
        while (num--) {
            *(char *) dest = *(char *) src;
            dest = (char *) dest + 1;
            src = (char *) src + 1;
        }
    } else {
        //后->前
        while (num--) {
            *((char *) dest + num) = *((char *) src + num);
        }
    }
    return ret;
}

//memmove的模拟实现
int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    my_memmove(arr1 + 2, arr1, 20);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr1[i]);
    }
    return 0;
}
