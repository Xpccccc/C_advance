#include <stdio.h>
#include <string.h>

//38、编写一函数，由实参传来一个字符串，统计此字符串中字母、数字、空格和其它字符的个数，在主函数中输入字符串以及输出上述结果。

void count_alpha(char *str, int *alpha, int *number, int *blank, int *other) {
    *alpha = 0;
    *number = 0;
    *blank = 0;
    *other = 0;
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z') {
            (*alpha)++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            (*number)++;
        } else if (str[i] == ' ') {
            (*blank)++;
        } else {
            (*other)++;
        }
    }
}

int main() {
    char str[100] = {0};
    gets(str);
    int alpha, number, blank, other = 0;//用于接收函数传递的值
    count_alpha(str, &alpha, &number, &blank, &other);
    printf("%s  alpha=%d number=%d blank=%d other=%d\n", str, alpha, number, blank, other);
    return 0;
}
