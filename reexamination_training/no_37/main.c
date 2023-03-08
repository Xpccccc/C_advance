#include <stdio.h>
#include <string.h>

//36、写一函数，将一个字符串中的元音字母复制到另一个字符串，然后输出。aeiou
int main() {
    char str[100] = {0};
    char str1[100] = {0};
    gets(str);
    for (int i = 0, j = 0; i < strlen(str); ++i) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            str1[j++] = str[i];//str1从0开始每次存一个字符再加一
    }
    for (int i = 0; i < strlen(str1); ++i) {
        printf("%c", str1[i]);
    }
    return 0;
}
