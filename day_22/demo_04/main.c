#include <stdio.h>
#include <string.h>

//HJ34 图片整理
int main() {
    char str[1000] = {0};
    gets(str);
    int len = strlen(str);
    //排序字母
    //冒泡排序
    for (int i = 0; i < len - 1; ++i) {
        int flag = 0;
        for (int j = 0; j < len - 1 - i; ++j) {
            if ((int) str[j] > (int) str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
                flag = 1;
            }
        }
        if (0 == flag) {
            break;
        }
    }
    printf("%s", str);
    return 0;
}