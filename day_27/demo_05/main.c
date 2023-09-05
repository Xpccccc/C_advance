#include <stdio.h>

typedef union {
    int a;
    struct {
        short b;
        short c;
    };
} X;

//联合，公用存储空间
int main() {
    X x;
    x.a = 0x20150810;
    printf("%x,%x\n", x.b, x.c);
}