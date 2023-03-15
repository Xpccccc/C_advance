#include <stdio.h>
#include <string.h>

//69、将一个字符串（小于10个字符）中的数字和字母分离，输出两个字符串。
int main() {
    char str[10] = {0};
    char str1[10] = {0};
    char str2[10] = {0};
    gets(str);
    int j = 0;
    int k = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            str1[j] = str[i];
            j++;
        } else if (str[i] >= 'A' && str[i] <= 'z') {
            str2[k] = str[i];
            k++;
        }
    }
    printf("字母=%s  数字=%s\n", str2, str1);
    return 0;
}
