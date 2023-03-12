#include <stdio.h>
#include <string.h>
#include <assert.h>

//将一个英文语句以单词为单位逆序排放。
// 如“I am a boy”，逆序排放后为“boy a am I”所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符。


void reverse(char *left, char *right) {
    assert(left && right);
    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main() {
    char arr[101] = {0};
    gets(arr);
    int len = strlen(arr);
    reverse(arr, arr + len - 1);//逆置字符串
    //abc def
    char *cur = arr;
    while (*cur) {
        char *start = cur;
        while (*cur != ' ' && *cur != '\0') {
            cur++;
        }
        //此时cur指向空格
        reverse(start, cur - 1);
        if (*cur != '\0')//cur指向\0可能出现死循环
            cur++;//跳过空格
    }
    printf("%s\n", arr);
    return 0;
}