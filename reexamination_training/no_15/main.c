#include <stdio.h>
#include <tgmath.h>

//14、用迭代法求 。求平方根的迭代公式为：
//要求前后两次求出的得差的绝对值少于 0.00001。


//牛顿迭代法
double my_sqrt(double a) {
    double x0 = a / 2;
    double x1 = (x0 + a / x0) / 2;
    while (fabs(x0 - x1) > 0.000001) {
        x0 = x1;
        x1 = (x0 + a / x0) / 2;
    }
    return x1;
}


int main() {
    double a = 0.0, x = 0.0;
    scanf("%lf", &a);//双精度lf
    x = my_sqrt(a);
    printf("%lf", x);
    return 0;

}
