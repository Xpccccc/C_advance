#include <stdio.h>
#include <stdlib.h>

//74、编写一个函数new, 对n个字符开辟连续的存储空间，此函数应返回一个指针，指向字符串开始的空间。
// New(n)表示分配n 个字节的内存空间。

char *New(int n) {
    char *str = (char *) malloc(sizeof(char) * n);
    return str;
}

int main() {
    int n = 0;
    scanf("%d", &n);
    char *ret = New(n);
    printf("%p\n",ret);
    return 0;
}
