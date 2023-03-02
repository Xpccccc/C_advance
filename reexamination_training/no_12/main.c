#include <stdio.h>

int is_runnian(int year) {
    if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)))
        return 1;
    else
        return 0;
}

//12、输入年月日，输出这一天是这一年的第几天。
int main() {
    int year, month, day = 0;
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d %d %d", &year, &month, &day);
    if (1 == is_runnian(year)) {
        arr[1] = 29;
    }
    for (int i = 0; i < month - 1; i++) {
        day += arr[i];
    }
    printf("%d\n", day);
    return 0;
}
