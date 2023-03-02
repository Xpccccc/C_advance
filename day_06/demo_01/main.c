#include <stdio.h>
#include <string.h>

//实现一个函数，可以左旋字符串中的k个字符。
//
//例如：
//
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
int main() {
    char str[100] = {0};
    int k = 0;
    scanf("%s %d", str, &k);
    int len = strlen(str);
    for (int i = len; i < len + k; i++) {
        str[i] = str[i - len];//将前k个元素移到字符串末尾
        str[i - len] = 0;//将前k个元素置空
    }
    printf("%s", str + k);
    return 0;
}
