#include <stdio.h>
#include <math.h>
//45、三角形面积为：sqrt(S*(S-m)*(S-n)*(S-k))。
// 其中S=(a+b+c)/2，a、b、c 为三角形的三边。
// 定义两个带参的宏，一个用来求S，另一个宏用来求area。
// 写程序，在程序中用带实参的宏来求面积area。

#define S(a, b, c)  (a+b+c)/2

#define area(a, b, c, s)  sqrt(s*(s-a)*(s-b)*(s-c))

int main() {
    float a, b, c, s, ss = 0;

    scanf("%f %f %f", &a, &b, &c);
    s = S(a, b, c);
    ss = area(a, b, c, s);
    printf("%.2f\n", ss);
    return 0;
}
