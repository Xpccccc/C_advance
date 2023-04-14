#include <stdio.h>
#include <string.h>

int main() {
    char arr1[20] = "hello \0xxxxx";
    char arr2[] = "abcdef";
    strncat(arr1,arr2,3);//从\0开始追加,并且追加后的字符末尾加上\0
    printf("%s\n",arr1);
    return 0;
}
