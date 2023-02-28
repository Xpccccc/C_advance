#include <stdio.h>

//一维数组，数组指针用法
int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int (*p)[10] = &arr;//p指向一个存有10个元素的整型数组 (存整型数组的地址)
    // p  --- &arr
    // *p --- *(&arr)
    // *p --- arr
    for (int i = 0; i < 10; i++) {
        printf("%d ", *((*p) + i));
        //printf("%d ",*((arr+i));
        //printf("%d ",arr[i);
    }
    return 0;
}
