#include <stdio.h>
#include <string.h>

int main() {
    char arr1[] = "abcdefg";
    char arr2[] = "abce";
    int ret = strncmp(arr1, arr2, 4);//对比前三个字符
    printf("%d\n", ret);
    return 0;
}
