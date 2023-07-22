#include <stdio.h>
#include <string.h>

//从一串英文句子中删除另一串英文的所有相同字母
int main() {
    char str1[101] = {0};
    char str2[101] = {0};
    gets(str1);
    gets(str2);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    str1[0] = str1[0] + 32;//首字母先变小字母
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            if (str1[i] == str2[j]) {
                str1[i] = '*';
            }
        }
    }
    int count = 0;
    for (int i = 0; i < len1; i++) {
        if (str1[i] != '*') {
            count++;
            if(count == 1)
                str1[i] = str1[i] - 32;//首字母变大写;
            printf("%c", str1[i]);

        }
    }
}
