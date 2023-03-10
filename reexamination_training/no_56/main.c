#include <stdio.h>

//55、定义一个结构体变量（包括年、月、日）。计算该日在本年中是第几天，注意闰年问题。
//4的整数倍，且不为100的整数倍----普通闰年  ；年数为400的整数倍----世纪闰年

typedef struct S {
    int year;
    int month;
    int day;
} S;

int Leap_year(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    else
        return 0;
}

int main() {
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    S s = {0};
    scanf("%d%d%d", &s.year, &s.month, &s.day);

    if (1 == Leap_year(s.year)) {
        arr[1] = 29;
        for (int i = 0; i < s.month - 1; ++i) {
            s.day += arr[i];
        }
    } else {
        for (int i = 0; i < s.month - 1; ++i) {
            s.day += arr[i];
        }
    }
    printf("%d\n", s.day);
    return 0;
}
