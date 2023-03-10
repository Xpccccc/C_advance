#include <stdio.h>

//56、写一个函数days,实现上面的计算。由主函数将年、月、日传递给days 函数，计算后将日数传回主函数输出。


int Leap_year(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}

int days(int year, int month, int day) {
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (1 == Leap_year(year)) {
        arr[1] = 29;
        for (int i = 0; i < month - 1; ++i) {
            day += arr[i];
        }
    } else {
        for (int i = 0; i < month - 1; ++i) {
            day += arr[i];
        }
    }
    return day;
}

int main() {
    int year, month, day = 0;
    scanf("%d%d%d", &year, &month, &day);
    int dayss = days(year, month, day);
    printf("%d\n", dayss);
    return 0;
}
