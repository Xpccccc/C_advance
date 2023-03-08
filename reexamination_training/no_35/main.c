#include <stdio.h>
#include <string.h>

//34、写一个函数，使输入的一个字符串按反序存放，在主函数中输入输出字符串。
int main() {
    char str[100] = {0};
    gets(str);
    int len = strlen(str);
    int left = 0;
    int right = len - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    for (int i = 0; i < len; ++i) {
        printf("%c", str[i]);
    }
    return 0;
}
