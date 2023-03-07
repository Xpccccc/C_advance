#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//模拟实现qsort的兄弟bubble_sort
//void qsort (void* base, size_t num, size_t size,
//            int (*compar)(const void*,const void*));

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

void Swap(char *p1, char *p2, int size) {
    while (size--) {//一个字节一个字节交换
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2++;
    }
}

void bubble_sort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *)) {
    //确定趟数
    for (int i = 0; i < num - 1; ++i) {
        //一趟冒泡排序的过程
        for (int j = 0; j < num - 1 - i; ++j) {
            //两个相邻元素的比较
            //arr[j] arr[j+1]
            //不知道base类型，只知道base大小，按字节来确定指针位置
            if (compar((char *) base + j * size, (char *) base + (j + 1) * size) > 0) {//升序
                //交换
                Swap((char *) base + j * size, (char *) base + (j + 1) * size, size);
            }
        }
    }
}


int main() {
    Student s[] = {{"zhangsan", 22},
                   {"lisi",     33},
                   {"wangwu",   21},
                   {"xupeng",   24}};
    int num = sizeof(s) / sizeof(s[0]);
    //qsort(s, num, sizeof(s[0]), compare_age);
    //bubble_sort(s, num, sizeof(s[0]), compare_age);
    bubble_sort(s, num, sizeof(s[0]), compare_name);
    return 0;
}
