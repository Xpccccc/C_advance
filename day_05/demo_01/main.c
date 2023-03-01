#include <stdio.h>

//一级指针
void test(int *arr) {
    printf("hh\n");
}

int main() {
    int arr[10] = {0};
    test(arr);
    int a = 0;
    test(&a);
    int *p = &a;
    test(p);

    return 0;
}
