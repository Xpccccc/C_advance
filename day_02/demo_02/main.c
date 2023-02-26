#include <stdio.h>

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//
//以下为4个嫌疑犯的供词:
//
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
int main() {
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    for (int A = 0; A <= 1; ++A) {
        for (int B = 0; B <= 1; ++B) {
            for (int C = 0; C <= 1; ++C) {
                for (int D = 0; D <= 1; ++D) {
                    if ((A == 0 && (B + C + D) == 1) + (C == 1) + (D == 1) + (D == 0) == 3)
                        printf("A=%d B=%d C=%d D=%d\n", A, B, C, D);
                }
            }
        }
    }
    printf("Hello, World!\n");
    return 0;
}
