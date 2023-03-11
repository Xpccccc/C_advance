#include <stdio.h>

//57、编写函数print,打印一个学生的成绩数，该数组中有5个学生的数据记录，
// 每个记录包括num、name、sore[3]，用主函数输入这些记录，用print函数输出这些记录。

typedef struct Student {
    int num;
    char name[20];
    int score[3]
} S;

int main() {
    S s[5] = {{1, "xp",  {55, 66, 77}},
              {2, "ch",  {66, 55, 33}},
              {3, "zfb", {77, 88, 99}},
              {4, "zsc", {44, 66, 44}},
              {5, "yrj", {88, 90, 99}}};
    for (int i = 0; i < 5; ++i) {
        printf("学号=%d 名字=%s 成绩=", s[i].num, s[i].name);
        for (int j = 0; j < 3; ++j) {
            printf("%d ", s[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}
