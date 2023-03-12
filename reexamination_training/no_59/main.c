#include <stdio.h>

//58、在上题的基础上，编写一个函数input,用来输入5 个学生的数据记录。

typedef struct Student {
    int num;
    char name[20];
    int score[3]
} S;

int main() {
    S s[5] = {0};
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &s[i].num);
        scanf("%s", s[i].name);
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &s[i].score[j]);
        }
    }
    for (int i = 0; i < 5; ++i) {
        printf("学号=%d 名字=%s 成绩=", s[i].num, s[i].name);
        for (int j = 0; j < 3; ++j) {
            printf("%d ", s[i].score[j]);
        }
        printf("\n");
    }
    return 0;
}

