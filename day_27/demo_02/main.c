#include <stdio.h>

//HJ46 截取字符串
int main() {
    char str[1000] = {0};
    int k = 0;
    gets(str);
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        printf("%c", str[i]);
    }
    return 0;
}