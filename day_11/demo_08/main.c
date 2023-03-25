#include<stdio.h>

//洛谷：P1179 [NOIP2010 普及组] 数字统计
int main() {
    int l = 0;
    int r = 0;
    int count = 0;
    scanf("%d %d", &l, &r);
    for (int i = l; i <= r; i++) {
        //2,12,20,21
        int temp = i;
        int n = 0;
        while (temp) {
            temp /= 10;
            n++;
        }
        int a = 10;
        temp = i;
        while (n-- && temp) {
            if ((temp % a) / (2 * a / 10) == 1 && (temp % a) % ((2 * a / 10)) == 0) {
                count++;
            }
            temp = temp - temp % a;
            a = a * 10;
        }
    }
    printf("%d\n", count);
    return 0;
}