#include <stdio.h>

//59、有10个学生，每个学生的数据包括学号、姓名、3门课的成绩，从键盘输入10个学生的数据，
// 要求打印出3门课的总平均成绩，以及最高分的学生的数据（包括学号、姓名、3门课成绩）

typedef struct Student {
    int no;
    char name[20];
    int score[3]
} S;

int main() {
    S s[10] = {0};
    //输入
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &s[i].no);
        scanf("%s", s[i].name);
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &s[i].score[j]);
        }
    }
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum = 0;
        for (int j = 0; j < 10; ++j) {
            sum += s[j].score[i];
        }
        printf("课%d的平均成绩=%.2f\n", i + 1, sum / 10.0);
    }

    int max = 0;
    int k = 0;
    for (int i = 0; i < 10; ++i) {
        sum = 0;
        for (int j = 0; j < 3; ++j) {
            sum += s[i].score[j];
        }
        if (sum > max) {
            max = sum;
            k = i;
        }
    }
    printf("学号=%d 名字=%s 成绩=", k, s[k].name);
    for (int i = 0; i < 3; ++i) {
        printf("%d ", s[k].score[i]);
    }
    return 0;
}
