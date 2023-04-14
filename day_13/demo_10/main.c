#include <stdio.h>
#include <assert.h>

int my_strcmp(const char *str1, const char *str2) {
    assert(str1 && str2);
    char *s1 = (char *) str1;
    char *s2 = (char *) str2;
    while (*s1 == *s2) {
        s1++;
        s2++;
        if (*s1 == *s2 && *s1 == '\0')
            return 0;
    }
    return *s1 - *s2;
}

//模拟实现strcmp
int main() {
    char arr1[] = "abcc";
    char arr2[] = "abcd";
    printf("%d\n", my_strcmp(arr1, arr2));
    return 0;
}
