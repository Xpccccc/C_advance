#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <tgmath.h>

int my_atoi(const char *str) {
    assert(str);
    int ret = 0;
    int len = strlen(str);
    int num = len;
    for (int i = 0; i < len; ++i) {
        ret += (str[i] - '0') * pow(10, num - 1);
        num--;
    }
    return ret;
}

//模拟实现atoi
//int atoi (const char * str);
int main() {
    char str[] = "124654353";
//    int ret = atoi(str);
//    printf("%d", ret);
    int ret = my_atoi(str);
    printf("%d", ret);
    return 0;
}
