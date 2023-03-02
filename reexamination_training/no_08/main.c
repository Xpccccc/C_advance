#include <stdio.h>

//8、求1!+2!+3!+4!+5!+…+20!

int fac(int n) {
    if (n <= 1)
        return 1;
    return n * fac(n - 1);
}

int main() {
    int n = 0;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        sum += fac(i);
    }
    printf("%d\n", sum);
    return 0;
}
