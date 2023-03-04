#include <stdio.h>

//16、打印出以下图案。
//*
//* * *
//* * * * *
//* * * * * * *
//* * * * *
//* * *
//*
int main() {
    char c = '*';
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 2 * i - 1; ++j) {
            printf("%c ", c);
        }
        printf("\n");
    }
    for (int i = 3; i >= 1; --i) {
        for (int j = 2 * i - 1; j >= 1; --j) {
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("Hello, World!\n");
    return 0;
}
