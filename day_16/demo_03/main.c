#include <stdio.h>      /* printf */
#include <stddef.h>     /* offsetof */

//将type的起始位置设置为0，来求偏移量
#define my_offsetof(type, member) (size_t)( &( ( ( type* )0 ) -> member) )

struct foo {
    char a;
    int b;
    char c[10];
    char d;
};

//offsetof宏的模拟实现
//offsetof (type,member)
int main() {

    printf("my_offsetof(struct foo,a) is %d\n", (int) my_offsetof(
    struct foo, a));
    printf("my_offsetof(struct foo,b) is %d\n", (int) my_offsetof(
    struct foo, b));
    printf("my_offsetof(struct foo,c) is %d\n", (int) my_offsetof(
    struct foo, c));
    printf("my_offsetof(struct foo,d) is %d\n", (int) my_offsetof(
    struct foo, d));
    return 0;
}