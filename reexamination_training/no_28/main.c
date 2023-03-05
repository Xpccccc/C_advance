#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//28、编一程序，将两个字符串连接起来，不要strcat函数。
int main() {
    char str1[] = "dsfdfsddsfvds";
    char str2[] = "dsjhfdsadjbds";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    char *str3 = (char *) malloc(sizeof(char) * (len1 + len2));
    for (int i = 0; i < len1; ++i) {
        str3[i] = str1[i];
    }
    //从str3后面接上str2
    for (int i = 0, j = len1; i < len2, j < len1 + len2; ++i, ++j) {
        str3[j] = str2[i];
    }
    str3[len1 + len2] = '\0';//字符串结尾符
    for (int i = 0; i < len1 + len2; ++i) {
        printf("%c", str3[i]);
    }
    return 0;
}
