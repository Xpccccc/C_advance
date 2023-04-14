#include <stdio.h>
#include <assert.h>

char *my_strcpy(char *dest, const char *src) {
    assert(src && dest);
    char *start = dest;
    char *p = (char *) src;
    while (*p) {
        *dest++ = *p++;
    }
    return start;
}

//递归实现strcpy
int main() {
    char arr1[] = "abcs";
    char arr2[5] = {0};
    printf("%s\n", my_strcpy(arr2, arr1));
    return 0;
}
