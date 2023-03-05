#include <stdio.h>
#include <stdlib.h>

//22、打印“魔方阵”，所谓魔方阵是指这样的方阵，它的每一行、每一列和对角线之和均相等。例如，三阶魔方阵为
//8  1  6
//3  5  7
//4  9  2
//要求打印出由 1～n2 的自然数构成的魔方阵。
int main() {
    int n = 0;
    scanf("%d", &n);
    int *arr = (int *) malloc(sizeof(int) * n * n);
    for (int i = 1; i <= n * n; ++i) {
        arr[i] = i;
    }

    return 0;
}
