#include <stdio.h>

typedef struct student {
    char name[10];
    int age
} S;

int main() {
    S s = {.age=10, .name="xp"};
    printf("%s %d\n", s.name, s.age);
    return 0;
}
