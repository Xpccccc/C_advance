#include <stdio.h>
#include <string.h>

//输入：输入一个字符串，字符串表示带有分数加、减运算的表达式（仅限个位数），如“1/3+1/2-2-1/3”，参与运算的数可能是分数（1/3表示的是分数），可能是整数
//输出：计算该表达式的值，要求最后结果以分数的形式输出。

//给定两个数，求这两个数的最小公倍数
int lowest_Common_Multiple(int a, int b) {
    int c = 0;
    int d = a * b;//a和b的乘积
    //辗转相除法
    while (a % b) {
        c = a % b;//余数
        a = b;
        b = c;
    }
    return d / b;
}
//111-1/2+3/5-5/9-1+1-2-2/3+5/6-3

//给定两个数，求这两个数的最大公约数
int greatest_Common_Divisor(int a, int b) {
    int c = 0;
    //辗转相除法
    while (a % b) {
        c = a % b;//余数
        a = b;
        b = c;
    }
    return b;
}

int main() {
    char str[100] = {0};
    int under[100] = {0};//记录所有分数的分母
    gets(str);
    int len = strlen(str);
    int j = 0;
//    memset(under, 1, 100 * sizeof(int));
    for (int i = 0; i < 100; ++i) {
        under[i] = 1;
    }
    for (int i = 0; i < len; ++i) {
        if (str[i] == '/') {
            //把所有分数的分母放到数组里以便于求最小公倍数
            under[j++] = str[i + 1] - '0';
        }
    }
    //numerator and denominator 分子和分母的单词
    //求最小公倍数 即初步确定分母
    int denominator = under[0];
    for (int i = 1; i < j; i++) {
        denominator = lowest_Common_Multiple(denominator, under[i]);
    }
    //对分数和整数进行加减
    //分子 这里初步确定分子
    int numerator = 0;
    for (int i = 0; i < len; ++i) {
        //对分数进行加减
        if (str[i] == '/') {
            //(i - 2 < 0) 是最左边边界条件
            if (str[i - 2] == '+' || (i - 2 < 0)) {
                numerator += (str[i - 1] - '0') * denominator / (str[i + 1] - '0');
            } else if (str[i - 2] == '-') {
                numerator -= (str[i - 1] - '0') * denominator / (str[i + 1] - '0');
            }
        }
        //对整数数进行加减
        //(i - 1 < 0) 是最左边边界条件 ,(i + 1 == len)是最右边边界条件
        if ((str[i - 1] == '-' && str[i + 1] == '+') ||
            (str[i - 1] == '-' && str[i + 1] == '-') ||
            (str[i - 1] == '-' && i + 1 == len)) {
            numerator -= (str[i] - '0') * denominator;
        } else if ((str[i - 1] == '+' && str[i + 1] == '+') ||
                   (str[i - 1] == '+' && str[i + 1] == '-') ||
                   (i - 1 < 0 && (str[i + 1] == '+' || str[i + 1] == '-' || i + 1 == len)) ||
                   (str[i - 1] == '+' && i + 1 == len)) {
            numerator += (str[i] - '0') * denominator;
        }
    }
    //再对分子分母求最大公约数 即化简
    int gcd = 0;
    gcd = greatest_Common_Divisor(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    printf("%d/%d\n", numerator, denominator);
//    printf("%d\n", lowest_Common_Multiple(18, 27));
//    printf("%d\n", greatest_Common_Divisor(27, 18));
    return 0;
}
