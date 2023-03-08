#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//前缀表不减一版本
void getNext(int *next, char *s) {
    //初始化 next
    int j = 0;
    next[0] = 0;
    for (int i = 1; i < strlen(s); i++) {    //注意 i 从 1 开始
        //若前后缀不相同
        while (j > 0 && s[i] != s[j]) {
            //则向前回退
            j = next[j - 1];
        }
        //若前后缀相同
        if (s[i] == s[j]) {
            //i 和 j 同时向后移动（i 的增加在 for 循环里）
            j++;
        }
        //将 j（前缀的长度）赋值给 next[i]
        next[i] = j;
    }
}

int strStr(char *haystack, char *needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    //当 needle 为空字符串时，返回 0
    if (len2 == 0) {
        return 0;
    }

    //构建 next 数组
    int *next = malloc(sizeof(int) * len2);
    getNext(next, needle);
    //next 记录的起始位置为 0，所以这里也从 0 开始
    int j = 0;
    for (int i = 0; i < len1; i++) {    //注意匹配时 i 从 0 开始
        //若不匹配
        while (j > 0 && haystack[i] != needle[j]) {
            //j 退回到之前匹配的位置
            j = next[j - 1];
        }
        //若匹配
        if (haystack[i] == needle[j]) {
            //i 和 j 同时向后移动（i 的增加在 for 循环里）
            j++;
        }
        //当 j 等于 needle 的长度时，说明字符串 haystack 里出现了字符串 needle
        if (j == len2) {
            //返回 needle 字符串出现的第一个位置
            return (i - len2 + 1);
        }
    }

    //若未找到则说明不存在，返回 -1
    return -1;
}

int main() {
    char str[] = "abcdababcdaabcd";
    char str1[] = "abcdaa";
    int ret = strStr(str, str1);
    printf("%d\n", ret);
    return 0;
}
