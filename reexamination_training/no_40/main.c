#include <stdio.h>

//39、写一函数，输入一行字符，将此字符串中最长的单词输出。
//  sdas d  dsanskdasd ajkdbsad jksdasbhdbdjhdsfsbhbcbd hsdcjsd c
//jksdasbhdbdjhdsfsbhbcbd

int cur_strlen(char *str) {
    int len = 0;
    while (*str != ' ' && *str != '\0') {
        str++;
        len++;
    }
    return len;
}

char *long_word(char *str, int *max_len) {
    //三个指针，一个指向目前最长的单词，一个指向下一个还没开始测试长度的单词起始位置，一个用来计算单词长度
    char *start = 0;//记录最长的单词的首字母地址
    *max_len = 0;//记录最长的单词长度
    while (*str != '\0') {
        if (*str != ' ') {
            int len = cur_strlen(str);//目前的单词长度
            if (len > *max_len) {
                *max_len = len;
                start = str;//目前最长的单词的首字母地址
            }
            str = str + len;//跳过当前单词
        }
        if (*str == ' ') {
            str++;//跳过空格
        }
    }
    return start;
}

int main() {
    char str[100] = {0};
    gets(str);
    int long_len = 0;//用来接收最长单词的长度
    char *word = long_word(str, &long_len);
    for (int i = 0; i < long_len; ++i) {
        printf("%c", word[i]);
    }
    return 0;
}
