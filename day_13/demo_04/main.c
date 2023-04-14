#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = "abcdef";
    char arr2[8] = "xxxx";
    strncpy(arr2, arr, 3);//若拷贝7个，不够的字符用\0补充
    printf("%s\n", arr2);
    return 0;
}
