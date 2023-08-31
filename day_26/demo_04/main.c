#include <stdio.h>
#include <string.h>

void reverse(char *str, char *left, char *right) {
    while (left < right) {
        char temp = *left;
        *left = *right;
        *right = temp;
        right--;
        left++;
    }
}


//HJ31 单词倒排
int main() {
    char str[10000] = {0};
    gets(str);
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (str[i] < 'A' || str[i] > 'z') {
            str[i] = ' ';//将非字母变空格
        }
    }
    //先整体逆置
    reverse(str, str, str + len - 1);
    //再每个单词逆置
    char *cur = str;
    while (*cur != '\0') {
        char *end = cur;//记录当前单词的最后一个字母位置后面一个
        while (*end != ' ' && *end != '\0') {//找出当前单词的最后一个字母位置后面一个
            end++;
        }
        reverse(cur, cur, end - 1);//将当前单词逆置
        if (*end != '\0') //不是最后一个单词就让cur移动到end+1的位置
            cur = end + 1;
        else
            cur = end;//end指向'\0'则结束cur后移了
    }
    //再将连续的多个空格弄成一个空格
    char str1[10000] = {0};
    int flag = 0;
    for (int i = 0, j = 0; i < len; ++i) {
        if (str[i] == ' ') {
            if (flag == 0) {
                str1[j++] = str[i];//第一次就放进去
                flag = 1;
            }
        } else {
            str1[j++] = str[i];
            flag = 0;
        }
    }
    printf("%s", str1);
    return 0;
}