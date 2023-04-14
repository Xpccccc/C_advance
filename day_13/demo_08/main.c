#include <stdio.h>
#include <assert.h>

char *my_strstr(const char *str1, const char *str2) {
    assert(str1 && str2);
    char *s1 = NULL;
    char *s2 = NULL;
    char *cp = (char *) str1;
    while (*cp) {
        s1 = cp;
        s2 = (char *) str2;
        while (*s1 && *s2 && *s1 == *s2) {
            s1++;
            s2++;
        }
        if (*s2 == '\0') {
            return cp;
        }
        cp++;
    }
    return NULL;
}

//strstr的模拟实现
int main() {
    char arr1[] = "abcdefg";
    char arr2[] = "bcdef";
    char *p = my_strstr(arr1, arr2);
    printf("%s\n", p);
    return 0;
}
