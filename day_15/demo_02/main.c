#include <stdio.h>
#include <math.h>

//每三个数字一个逗号
int main() {
    long long n = 0;
    int count = 0;//每三个数字一个逗号
    scanf("%lld", &n);
    int sum = 0;//记录n的位数
    long long num = n;
    //计算n的位数
    while (num) {
        num /= 10;
        sum++;
    }
    int dot = sum/3 + 1;//逗号个数
    sum--;
    num = n;//重置num
    while (sum != -1) {
        printf("%d", (int) (num / (pow(10, sum))));
        num = num % (long long) (pow(10, sum));
        sum--;
        count++;
        if (3 == count&& sum!=-1) {
            printf(",");
            count = 0;//重置count
        }
    }
    return 0;
}