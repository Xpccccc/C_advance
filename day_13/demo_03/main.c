#include <stdio.h>
#include <assert.h>

char *my_strcat(char *dest, const char *src) {
    char *ret = dest;
    assert(dest && src);
    while (*dest != '\0') {
        dest++;
    }
    while (*dest++ = *src++) { ;
    }
    return ret;
}

//strcat的模拟实现
int main() {
    char arr1[20] = "hello ";
    char arr2[] = "world";
    char *ret = my_strcat(arr1, arr2);
    printf("%s\n", ret);
    return 0;
}
