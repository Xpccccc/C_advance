#include <stdio.h>
#include <tgmath.h>

int is_sushu(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

//12、输出比2017大的素数。
int main() {
    for (int i = 2017;i<2200; i++) {
        if (1 == is_sushu(i))
            printf("%d ", i);
    }
    return 0;
}
