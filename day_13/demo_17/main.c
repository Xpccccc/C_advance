#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = "hello world!";
    memset(arr, 'x', 5);//将前面num个字节的内存块设置为特定的值（字符）
    printf("%s\n", arr);
    return 0;
}
