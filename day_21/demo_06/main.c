#include <stdio.h>

//判断是否合法
int is_Legal(char str[]) {
    int big_alph = 0, small_alph = 0, num_alph = 0, len = 0;
    if (str[0] >= '0' && str[0] <= '9') {
        return 0;//不合法
    }
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            small_alph++;
            len++;
            str++;
        } else if (*str >= '0' && *str <= '9') {
            num_alph++;
            len++;
            str++;
        } else if (*str >= 'A' && *str <= 'Z') {
            big_alph++;
            len++;
            str++;
        } else {
            return 0;//不合法
        }
    }
    if ((len >= 8) && ((small_alph + big_alph >= 2) || (small_alph + num_alph >= 2) || (num_alph + big_alph >= 2))) {
        return 1;//合法
    } else {
        return 0;
    }
}


//OR141 密码检查
int main() {
    int n = 0;
    char str[100] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (is_Legal(str) == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}