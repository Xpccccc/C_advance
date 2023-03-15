#include <stdio.h>
#include <tgmath.h>
#include <string.h>

//68、写一函数，输入一个十六进制数，输出相应的十进制数。

void print(char *str) {
    int len = strlen(str);
    int sum = 0;
    for (int i = len-1; i >=0; --i) {
        if (str[i] == 'A') {
            sum += 10 * pow(16, len-1-i);
        } else if (str[i] == 'B') {
            sum += 11 * pow(16, len-1-i);
        } else if (str[i] == 'C') {
            sum += 12 * pow(16, len-1-i);
        } else if (str[i] == 'D') {
            sum += 13 * pow(16, len-1-i);
        } else if (str[i] == 'E') {
            sum += 14 * pow(16, len-1-i);
        } else if (str[i] == 'F') {
            sum += 15 * pow(16, len-1-i);
        } else {
            sum += (str[i] - '0') * pow(16, len-1-i);//字符是从左往右
        }
    }
    printf("%d", sum);
}

int main() {
    char str[10] = {0};
    gets(str);
    print(str);
    return 0;
}
