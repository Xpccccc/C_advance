#include <stdio.h>
#include <string.h>

//洛谷：P1320 压缩技术（续集版）
int main() {
    char arr[40000] = {0};
    char str[200] = {0};
    scanf("%s", str);
    int n = strlen(str);
    strcat(arr, str);
    for (int k = 2; k <= n; k++) {
        scanf("%s", str);
        strcat(arr, str);
    }
    printf("%d ", n);
    int count = 0;
    char num = '0';
    for (int j = 0; j <= strlen(arr); j++) {
        if (num == arr[j]) {
            count++;
        } else {
            num = arr[j];
            printf("%d ", count);
            count = 1;
        }
    }
    return 0;
}

