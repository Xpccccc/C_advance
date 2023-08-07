#include <stdio.h>

int is_Leap_Year(int year) {
    //四年一闰，百年不闰，四百年再闰
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        return 1;
    } else {
        return 0;;
    }
}

//HJ73 计算日期到天数转换
int main() {
    int year = 0, month = 0, day = 0;
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d%d", &year, &month, &day);
    //首先得判断是否闰年
    if (1 == is_Leap_Year(year)) {
        //是闰年
        arr[1] = 29;//闰年2月29天
        for (int i = 0; i < month - 1; i++) {
            day += arr[i];
        }
    } else {
        for (int i = 0; i < month - 1; i++) {
            day += arr[i];
        }
    }
    printf("%d\n", day);
    return 0;
}