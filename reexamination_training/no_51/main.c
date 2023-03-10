#include <stdio.h>

//50、输入三个整数，按由小到大的顺序输出。----------指针
int main() {
    int a, b, c = 0;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) {//a的位置作为最小数
        int t = a;
        a = b;
        b = t;
    }
    if (b > c) {//b的位置作为第二小数
        int t = b;
        b = c;
        c = t;
        if (a > b) {//b和c的值交换了的情况下。再比较a和b
            int t = a;
            a = b;
            b = t;
        }
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}
