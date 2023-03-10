#include <stdio.h>

//51、输入三个字符串，按由小到大的顺序输出
int main() {
    char a, b, c = 0;
    scanf("%c %c %c", &a, &b, &c);
    if (a > b) {
        char t = a;
        a = b;
        b = t;
    }
    if (b > c) {
        char t = b;
        b = c;
        c = t;
        if (a > b) {
            char t = a;
            a = b;
            b = t;
        }
    }
    printf("%c %c %c\n", a, b, c);
    return 0;
}
