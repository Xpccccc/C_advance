#include <stdio.h>
#include <string.h>

//40、写一函数用起泡法对输入的个字符按由小到大的顺序排列。

void bubble_str(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        //一趟冒泡排序
        for (int j = 0; j < len - 1 - i; ++j) {
            if (str[j] - str[j + 1] > 0) {
                //交换
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main() {
    char str[10] = {0};
    gets(str);
    bubble_str(str);
    printf("%s\n", str);
    return 0;
}
