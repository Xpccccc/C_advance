#include <stdio.h>

//HJ97 记负均正
int main() {
    int n = 0;
    int num[2001] = {0};
    int count_neg = 0, count_zero = 0;//记录负数个数
    double avg = 0.0l;
    scanf("%d", &n);
    int i = 0;
    while (i < n) {
        scanf("%d", &num[i]);
        if (num[i] < 0) {
            count_neg++;
        } else if (num[i] > 0) {
            avg += num[i];
        } else {
            count_zero++;
        }
        i++;
    }
    avg /= (n - count_neg - count_zero);
    //全0
    if (count_zero == n)
        avg = 0.0l;
    printf("%d %.1f\n", count_neg, avg);
    return 0;
}