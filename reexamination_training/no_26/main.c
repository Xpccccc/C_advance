#include <stdio.h>

//25、有一篇文章，共有3行文字，每行有个80字符。
//要求分别统计出其中英文大写字母、小写字母、空格以及其它字符的个数。
int main() {
    char str1[80] = {0};
    char str2[80] = {0};
    char str3[80] = {0};
    int big_alpha = 0;
    int small_alpha = 0;
    int blank_alpha = 0;
    int other_alpha = 0;
    gets(str1);
    gets(str2);
    gets(str3);
    for (int i = 0; i < 80; ++i) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') {
            big_alpha++;
        }
        if (str2[i] >= 'A' && str2[i] <= 'Z') {
            big_alpha++;
        }
        if (str3[i] >= 'A' && str3[i] <= 'Z') {
            big_alpha++;
        }
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            small_alpha++;
        }
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            small_alpha++;
        }
        if (str3[i] >= 'a' && str3[i] <= 'z') {
            small_alpha++;
        }
        if (str1[i] == ' ') {
            blank_alpha++;
        }
        if (str2[i] == ' ') {
            blank_alpha++;
        }
        if (str3[i] == ' ') {
            blank_alpha++;
        }
    }
    other_alpha = 80 * 3 - big_alpha - small_alpha - big_alpha;
    printf("big_alpha=%d small_alpha=%d blank_alpha=%d other_alpha=%d\n", big_alpha, small_alpha, blank_alpha,
           other_alpha);
    printf("Hello, World!\n");
    return 0;
}
