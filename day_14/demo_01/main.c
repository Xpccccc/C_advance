#include <stdio.h>

int find_num(int arr[][3], int r, int c, int k) {
    int x = 0;
    int y = c - 1;
    while (x <= r - 1 && y >= 0) {
        if (arr[x][y] < k) {
            x++;
        } else if (arr[x][y] < k) {
            y--;
        } else {
            return 1;
        }
    }
    return 0;
}

//杨氏矩阵,找矩阵中的元素，复杂度不超过O(n)
int main() {
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 0;
    scanf("%d", &k);
    int ret = find_num(arr, 3, 3, k);
    printf("%d\n", ret);
    return 0;
}
