#include <stdio.h>
#include <math.h>

//洛谷：P1307 [NOIP2011 普及组] 数字反转

int main() {
    int n = 0;
    int sum = 0;
    scanf("%d", &n);
    if (n >= 0) {
        int temp = n;
        int count = 0;
        while (temp) {
            temp /= 10;
            count++;
        }
        temp = n;
        while (count) {
            sum += (temp % 10) * pow(10, count - 1);
            temp /= 10;
            count--;
        }
        printf("%d\n", sum);
    } else {
        int temp = -n;
        int count = 0;
        while (temp) {
            temp /= 10;
            count++;
        }
        temp = -n;
        while (count) {
            sum += (temp % 10) * pow(10, count - 1);
            temp /= 10;
            count--;
        }
        printf("%d\n", -sum);
    }
    return 0;
}