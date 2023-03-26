#include <stdio.h>

//洛谷：P1304 哥德巴赫猜想

int is_zhishu(int n) {
    int flag = 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            flag = 1;
            return 0;
        }
    }
    if (0 == flag) {
        return 1;
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    for (int i = 4; i <= n; i += 2) {
        for (int j = 2; j < i; j++) {
            if (1 == is_zhishu(j) && 1 == is_zhishu(i - j)) {
                printf("%d=%d+%d\n", i, j, i - j);
                break;
            }
        }
    }
    return 0;
}