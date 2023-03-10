#include <stdio.h>
#include <string.h>

//49、用条件编译方法实现以下功能：------不会
//输入一行电报文字，可以任选两种输出，一为原文输出；一为将字母变成其下一字母（如’a’变成’b’……’z’变成’ａ’其它字符不变）。用命令来控制是否要译成密码。例如：
//#define CHANGE 1
//则输出密码。若：
//#define CHANGE 0
//则不译为密码，按原码输出。

#define CHANDE 0

int main() {
    char str[100] = {0};
    gets(str);
    if (CHANDE) {
        for (int i = 0; i < strlen(str); ++i) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                if (str[i] == 'z')
                    str[i] = 'a';
                else
                    str[i] = str[i] + 1;
            }
            if (str[i] >= 'A' && str[i] <= 'Z') {
                if (str[i] == 'Z')
                    str[i] = 'A';
                else
                    str[i] = str[i] + 1;
            }
        }
    }
    printf("%s\n", str);
    return 0;
}
