#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

//31、求方程的根，用三个函数分别求当b2-4ac 大于0、等于0、和小于0 时的根，并输出结果。从主函数输入a、b、c的值。

float *root_2(int a, int b, int c) {
    float *arr = (float *) malloc(sizeof(float) * 2);
    arr[0] = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);//求根公式
    arr[1] = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);//求根公式
    return arr;
}

float *root_1(int a, int b, int c) {
    float *arr = (float *) malloc(sizeof(float) * 2);
    arr[0] = -b / (2 * a);//求根公式
    arr[1] = -b / (2 * a);//求根公式
    return arr;
}

void root_xu(int a, int b, int c) {
    float *arr = (float *) malloc(sizeof(float) * 2);
    float x1 = -b / (2 * a);//实部
    float x2 = sqrt(-b * b + 4 * a * c) / (2 * a);//虚部,注意根号里要是正数
    printf("根1=%.2f+%.2fi 根2=%.2f-%.2fi", x1, x2, x1, x2);
}

int main() {
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);
    //b2-4ac 大于0有两个根
    if (b * b - 4 * a * c > 0) {
        float *arr = root_2(a, b, c);
        for (int i = 0; i < 2; ++i) {
            printf("%.2f ", arr[i]);
        }
    } else if (b * b - 4 * a * c == 0) {    //b2-4ac 等于0有两个相等的根
        root_1(a, b, c);
        float *arr = root_1(a, b, c);
        for (int i = 0; i < 2; ++i) {
            printf("%.2f ", arr[i]);
        }
    } else {    //b2-4ac 小于0 时虚根
        root_xu(a, b, c);
    }

    return 0;
}
