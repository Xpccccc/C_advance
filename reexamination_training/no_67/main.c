#include <stdio.h>

//66、有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，
// 假如兔子都不死，问每个月的兔子总数为多少？输入int型表示month，输出兔子总数int型

int rabbit(int month) {
    if (month == 1 || month == 2)
        return 1;
    return rabbit(month - 1) + rabbit(month - 2);//当月份大于 2 时，兔子数为上个月的兔子数加上上上个月的兔子数
}

int main() {
    int month = 0;
    scanf("%d", &month);
    printf("%d", rabbit(month));
    return 0;
}
