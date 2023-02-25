#include <stdio.h>

int check_sys() {
    int a = 1;
    return *(char *) &a;
}

//判断系统大端小端存储
int main() {
    if (check_sys() == 1) {
        printf("小端\n");
    } else {
        printf("大端\n");
    }
    return 0;
}
