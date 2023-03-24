#include <stdio.h>

//洛谷：P1151 子数整数
int main() {
    int k = 0;
    int arr[3] = {0};
    scanf("%d", &k);
    for (int i = 10000; i <= 30000; i++) {
        arr[0] = i / 100;
        arr[1] = (i % 10000) / 10;
        arr[2] = i % 1000;
        int flag = 0;
        for (int j = 0; j < 3; j++) {
            if ((arr[j] % k) != 0) {
                flag = 1;
                break;
            }
        }
        if (0 == flag) {
            printf("%d\n", i);
        }
    }
    return 0;
}
