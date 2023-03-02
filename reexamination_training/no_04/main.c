#include <stdio.h>

//4、输入一个华氏温度，要求输出摄氏温度。公式为c=5(F-32)/9输出要求有文字说明，取位2小数。
int main() {
    float f = 0;
    scanf("%f", &f);
    float c = 5 * (f - 32) / 9.0;
    printf("摄氏度为%.2f\n", c);
    return 0;
}
