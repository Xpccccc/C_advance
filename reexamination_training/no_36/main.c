#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//35、写一函数，将两个字符串连接。

char *my_strcat(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *str3 = (char *) malloc(sizeof(char) * (len1 + len2) + 1);
    for (int i = 0; i < len1; ++i) {
        str3[i] = str1[i];
    }
    for (int i = len1, j = 0; j <= len2; ++i, ++j) {//'\0'也接上了
        str3[i] = str2[j];
    }
    return str3;
}

int main() {
    char str1[100] = {0};
    char str2[100] = {0};
    gets(str1);
    gets(str2);
    char *str3 = my_strcat(str1, str2);
    for (int i = 0; i < strlen(str3); ++i) {
        printf("%c", str3[i]);
    }
    return 0;
}
