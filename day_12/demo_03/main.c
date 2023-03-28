#include<stdio.h>

//洛谷：P1554 梦中的统计
int main() {
    long long m = 0, n = 0;
    scanf("%lld %lld", &m, &n);
    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0, count6 = 0, count7 = 0, count8 = 0, count9 = 0;
    for (long long i = m; i <= n; i++) {
        int temp = i;
        while (temp) {
            if (0 == temp % 10) {
                count0++;
            } else if (1 == temp % 10) {
                count1++;
            } else if (2 == temp % 10) {
                count2++;
            } else if (3 == temp % 10) {
                count3++;
            } else if (4 == temp % 10) {
                count4++;
            } else if (5 == temp % 10) {
                count5++;
            } else if (6 == temp % 10) {
                count6++;
            } else if (7 == temp % 10) {
                count7++;
            } else if (8 == temp % 10) {
                count8++;
            } else if (9 == temp % 10) {
                count9++;
            }
            temp /= 10;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d\n", count0, count1, count2, count3, count4, count5, count6, count7, count8,
           count9);
    return 0;
}