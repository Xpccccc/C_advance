#include <stdio.h>

//二级指针
void test(int **arr) {
    printf("hh\n");
}

int main() {
    int *arr[10] = {0};//数组里存的是int* 类型的元素，那指向int* 的地址的指针为int**
    test(arr);//arr数组首元素地址，
    int** p = arr;
    test(p);
    return 0;
}


