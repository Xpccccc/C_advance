#include <stdio.h>
#include <string.h>

//26、7.12有一行电文译文下面规律译成密码：
//A->Z a->z
//B->Y b->y
//C->X c->x
//…
//即第一个字母变成第26个字母，第i个字母变成第（26-i+1）个字母。非字母字符不变，要求编程序将密码回原文，并打印出密码和原文。
int main() {
    char str[] = "GHJHbjhbsasbxajhsbask-=[.ksaksaAHSJA";
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    for (int i = 0; i < len; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + 'Z' - str[i];//将第i个字母变成第（26-i+1）个字母
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + 'z' - str[i];//将第i个字母变成第（26-i+1）个字母
        }
    }
    for (int i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    return 0;
}
