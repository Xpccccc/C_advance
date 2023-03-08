#include <stdio.h>

//46、给年份year，定义一个宏，以判别该年份是否闰年。
//提示：宏名可以定义为LEAP_YEAR，形参为y，既定义宏的形式为#define LEAP_YEAR(y)（读者设计的字符串）
// 在程序中用以下语句输出结果：
//if (LEAP_YEAR(year)) printf("%d is a leap year",year);
//else printf ("%d is not a leap year",year);
#define LEAP_YEAR(y) ((y%400==0)||(y%4==0&&y%100!=0))?1: 0

int main() {
    int year = 0;
    scanf("%d", &year);
    if (LEAP_YEAR(year))
        printf("%d is a leap year", year);
    else
        printf("%d is not a leap year", year);
    return 0;
}
