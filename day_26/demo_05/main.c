#include <stdio.h>

int rabbit(int n) {
    if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
        return rabbit(n - 1) + rabbit(n - 2);//斐波那契
    // 1 1 2 3 5 8  当前值等于前两个值的和
    //     1 1 2
    //       1 1 2
}

//HJ37 统计每个月兔子的总数
int main() {
    int n = 0;
    scanf("%d", &n);
    int ret = rabbit(n);
    printf("%d", ret);
    return 0;
}

