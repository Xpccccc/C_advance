#include <stdio.h>



//洛谷：P1161 开灯

typedef struct Operate {
    float a;
    int t;
} Operate;


int main() {
    int n = 0;
    int arr[2000000] = {0};
    scanf("%d", &n);
    Operate op[5000] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%f %d", &(op[i].a), &(op[i].t));
    }
    for (int i = 0; i < n; i++) {
        int k = 1;
        for (int j = (int) (op[i].a); j <= (int) (op[i].a * op[i].t);) {
            if (arr[j] == 0)
                arr[j] = 1;
            else
                arr[j] = 0;
            j = (int) ((++k) * op[i].a);
        }
    }
    for (int i = 0; i < 2000000; i++) {
        if (1 == arr[i])
            printf("%d\n", i);
    }
    return 0;
}