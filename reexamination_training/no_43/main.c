#include <stdio.h>

//42、输入10 个学生5 门课的成绩，分别用函数求：
// ①每个学生平均分；②每门课的平均分；③找出最高分所对应的学生和课程；
// ④求平均分方差：δ=[SXi^2]/n-(SXi/n)^2。

typedef struct Stu {
    char name[20];
    float course[5];//五门课程
} S;

void stu_avg(S s[]) {
    float sum = 0.0;
    //每个学生的平均成绩
    for (int i = 0; i < 10; ++i) {
        sum = 0.0;
        for (int j = 0; j < 5; ++j) {
            sum += s[i].course[j];
        }
        printf("%s的平均成绩为%.2f\n", s[i].name, sum / 5.0);
    }
    //每门课的平均成绩
    for (int i = 0; i < 5; ++i) {
        sum = 0.0;
        for (int j = 0; j < 10; ++j) {
            sum += s[j].course[i];
        }
        printf("course%d的平均成绩是%.2f\n", i + 1, sum / 10);
    }
    //最高分对应的学生和课程
    for (int i = 0; i < 5; ++i) {
        float max = 0.0;
        int k = 0;
        for (int j = 0; j < 10; ++j) {
            if (s[j].course[i] > max) {
                max = s[j].course[i];
                k = j;//记录最高分的学生
            }
        }
        printf("课程%d的最高分是%.2f 学生是%s\n", i + 1, max, s[k].name);
    }

}


int main() {
    S s[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%s", s[i].name);//输入姓名
        for (int j = 0; j < 5; ++j) {
            scanf("%f", &s[i].course[j]);//输入成绩
        }
    }
    stu_avg(s);

    return 0;
}
