#include <stdio.h>
#include <string.h>

//54、有一字符串，包含n个字符。写一函数，将此字符串中从第m个字符开始的全部字符复制成为另一个字符串。
int main() {
    char str[100] = {0};
    char str1[100] = {0};
    gets(str);
    int m = 0;
    scanf("%d", &m);
    for (int i = 0; i < strlen(str) - m; ++i) {
        str1[i] = str[i + m];
    }
    printf("%s\n", str1);
    return 0;
}
