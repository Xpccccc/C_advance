#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = "1014647664@qq.com";
    char buf[20] = {0};
    const char *p = "@.";
    strcpy(buf, arr);
    char *str = NULL;
    for (str = strtok(buf, p); str != NULL; str = strtok(NULL, p)) {
        //strtok每分割一次，返回值是每次分割后的字符串的首地址，将分割符变为\0。分割到最后一次，返回NULL,
        printf("%s\n", str);
    }
    return 0;
}
