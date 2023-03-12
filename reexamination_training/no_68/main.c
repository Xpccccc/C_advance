#include <stdio.h>

//67、写几个函数：①输个职工的姓名和职工号；②按职工号由小到大顺序排序，姓名顺序也随之调整；
//③要求输入一个职工号，用折半法找出该职工的姓名，从主函数输入要查找的职工号，输出该职工姓名。

typedef struct Worker {
    int no;
    char name[20]
} Worker;

void sc(Worker *w) {
    for (int i = 0; i < 5; ++i) {
        scanf("%d %s", &w[i].no, w[i].name);
    }
}

void sort(Worker *w) {
    //冒泡排序
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5 - 1 - i; ++j) {
            if (w[j + 1].no < w[j].no) {
                //交换
                Worker temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

            }
        }
    }
}

char *search(Worker *w, int n) {
    int left = 0;
    int right = 4;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (n > mid) {
            left = mid + 1;
        } else if (n < mid) {
            right = mid - 1;
        } else {
            return w[mid-1].name;//工号从1开始
        }
    }
    return NULL;//没找到
}


int main() {
    Worker w[5] = {0};
    //输入
    sc(w);
    //排序
    sort(w);
    int n = 0;
    printf("输入要查找的工号:");
    scanf("%d", &n);
    //折半查找
    char *ret = search(w, n);
    printf("%s\n", ret);
    return 0;
}
