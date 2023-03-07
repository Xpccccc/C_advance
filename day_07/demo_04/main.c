#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int age;
} Student;


int compare_age(const void *p1, const void *p2) {
    return ((Student *) p1)->age - ((Student *) p2)->age;
}

int compare_name(const void *p1, const void *p2) {
    return strcmp(((Student *) p1)->name, ((Student *) p2)->name);
}

//使用qsort排序数据
int main() {
    Student s[] = {{"zhangsan", 22},
                   {"lisi",     33},
                   {"wangwu",   21},
                   {"xupeng",   24}};
    int num = sizeof(s) / sizeof(s[0]);
    qsort(s, num, sizeof(s[0]), compare_name);
    return 0;
}
