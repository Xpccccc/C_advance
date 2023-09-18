#include <stdio.h>
#include <string.h>
#include <tgmath.h>
#include <stdlib.h>

//输入：输入一个字符串，字符串表示带有分数加、减运算的表达式，如“1/3+1/2-2-1/3”，参与运算的数可能是分数（1/3表示的是分数），可能是整数
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

//给定两个数，求这两个数的最大公约数
int greatest_Common_Divisor(int a, int b) {
    if (a < 0)
        a = -a;
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
    gets(str);
    int under[100] = {0};//记录所有分数的分母 反着记录 ，因为反正才好算每个大于等于9的分母
    int up[100] = {0};//记录所有分数的分子 反着记录 ，因为反正才好算每个大于等于9的分子
    char symbol[100] = {0};//记录符号
    //先看看首字母是不是'-'，不是符号就加个'+'，方便运算
    char str1[101] = {0};
    if (str[0] != '-') {
        strcat(str1, "+");
        strcat(str1, str);
    } else {
        //将str拷贝到str1
        strcpy(str1, str);
    }
    int len = strlen(str1);
    int k = 0;//用于计算 under 的元素乘以10的指数次
    int m = 0;//用于计算 up 的元素乘以10的指数次
    int pd = 0;//记录under的指针
    int pp = 0;//记录up的指针
    int ps = 0;//记录symbol的指针
    for (int i = len - 1; i >= 0;) {
        if (str1[i] >= '0' && str1[i] <= '9') {
            while ((str1[i] != '/') && (str1[i] != '+' && str1[i] != '-')) {
                under[pd] += (str1[i] - '0') * pow(10, k);
                k++;
                i--;
            }
            k = 0;
            if (str1[i] != '/') {
                //此时i指针指向符号
                symbol[ps++] = str1[i];//记录符号
                //纯数字当分子
                up[pp++] = under[pd];// 因为此时是纯数字 所以under[pd]记录的是分子，直接赋值给up
                //由于是纯数字，所以分母置为1
                under[pd++] = 1;
                i--;//继续移到数字的位置上
            } else {
                //此时i走到了'/'
                pd++;//确定当前不是纯数字
                i--;//先移到数字的位置上
                while (str1[i] != '+' && str1[i] != '-') {
                    up[pp] += (str1[i] - '0') * pow(10, m);
                    m++;
                    i--;
                }
                pp++;
                m = 0;
                //此时i指针指向符号
                symbol[ps++] = str1[i];//记录符号
                i--;//继续移步到数字头上
            }
        }
    }
    //计算分母的最小公倍数 当分母
    //numerator and denominator 分子和分母的单词
    int denominator = under[0]; //记录 分母
    for (int i = 1; i < pd; ++i) {
        denominator = lowest_Common_Multiple(denominator, under[i]);
    }
    int numerator = 0;//记录 分子,刚好符号和所有分式的个数相同,因为加了个'+'
    //这里进行运算的时候也得反着来，因为前面记录分子分母符号都是反着来，且对分子加减看它前面的符号
    for (int i = ps - 1; i >= 0; --i) {
        if (symbol[i] == '-') {
            numerator -= up[i] * denominator / under[i];
        } else {
            numerator += up[i] * denominator / under[i];
        }
    }
    //计算分子分母的最大公约数 ，用来约分
    int greatest_common_divisor = greatest_Common_Divisor(numerator, denominator);
    numerator /= greatest_common_divisor;
    denominator /= greatest_common_divisor;
    if (abs(numerator) < denominator)
        printf("%d/%d\n", numerator, denominator);
    else {
        int a = 0;
        if (numerator < 0) {
            a = abs(numerator)/denominator;
            numerator += a * denominator;
            a = -a;
            numerator = -numerator;
        } else {
            a = numerator/denominator;
            numerator -= a * denominator;
        }
        printf("%d %d/%d\n", a, numerator, denominator);
    }
    return 0;

}
