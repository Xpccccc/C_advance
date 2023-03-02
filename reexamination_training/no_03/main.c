#include <stdio.h>

#define pi 3.14

//3、设圆半径 r=1.5，圆柱高 h=3，求圆周长、圆面积、圆球表面积、圆球体积、
//圆柱体积。用scanf输入数据，输出计算结果，输出时要求文字说明，取小数点后两位数字
int main() {
    float r = 1.5;
    int h = 3;
    float circle_length = 2 * pi * r;//圆周长
    float area = pi * r * r;//圆面积
    float surface_area = 4 * pi * r * r;//圆球表面积
    float body_area = 4 * pi * r * r * r / 3;//圆球体积
    float column_area = area * h;//圆柱体积
    printf("圆周长=%.2f 圆面积=%.2f 圆球表面积=%.2f 圆球体积=%.2f 圆柱体积=%.2f\n", circle_length, area, surface_area, body_area,
           column_area);
    return 0;
}
