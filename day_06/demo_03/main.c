#include <stdio.h>
#include <string.h>
#include <assert.h>

//写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
//
//例如：给定s1 =AABCD和s2 = BCDAA，返回1
//给定s1=abcd和s2=ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

//左旋一个字符函数
void left_spin(char *str) {
    assert(str);
    int len = strlen(str);
    char temp = str[0];
    int i = 0;
    for (i = 0; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[i] = temp;//将第一个字符放到最后面
}
//判断s2是否是s1左旋的字符串
int is_left_spin(char *s1, char *s2) {
    assert(s1 && s2);
    for (int i = 0; i < strlen(s1); i++) {
        left_spin(s1);//每次左旋一个字符
        if (strcmp(s1, s2) == 0)
            return 1;
    }
    return 0;
}
int main() {
    char s1[] = "AABCD";
    char s2[] = "BCDAA";
    int ret = is_left_spin(s1, s2);
    if (ret == 1)
        printf("%d\n", ret);
    else
        printf("%d\n", ret);
    return 0;
}
