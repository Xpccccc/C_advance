#include <stdio.h>
#include <string.h>

int main() {
    char arr1[] = "abcdef";
    char arr2[] = "bcd";
    char *p = strstr(arr1, arr2);//返回子串首地址
    printf("%s\n", p);
    return 0;
}
