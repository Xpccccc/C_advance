#include <stdio.h>
#include <string.h>

//HJ10 字符个数统计
int main() {
    char str[501] = {0};
    int arr[128] = {0};//将字符转换为ascii码，对应数组中的位置置1;这表示存在的某种字符
    char *p = str;
    gets(str);
    int len = strlen(str);
    str[len] = '\n';
    while (*p != '\n') {
        if (arr[(int) (*p)] != 1) {
            arr[(int) (*p)] = 1;//对应数组中的位置的值置1;这表示存在的某种字符
        }
        p++;
    }
    int count = 0;
    //遍历找1
    for (int i = 0; i < 128; ++i) {
        if (arr[i] == 1) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}