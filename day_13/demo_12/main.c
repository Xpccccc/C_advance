#include <stdio.h>
#include <string.h>

int main() {
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[5] = {0};
    memcpy(arr2, arr1, 20);//arr1拷贝20个字节到arr2
    for (int i = 0; i < 5; ++i) {
        printf("%d ",arr2[i]);
    }
    return 0;
}
