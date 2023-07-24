//
// Created by 徐鹏 on 2023/7/22.
//

#include "contact.h"

//初始化通讯录
void InitContact(Contact *pc) {
    assert(pc);
    memset(pc->data, 0, sizeof(pc->data));
    pc->sz = 0;
}

//增加通讯录
void AddContact(Contact *pc) {
    assert(pc);
    if (pc->sz == MAX) {
        printf("该通讯录已满\n");
        return;
    }
    printf("请输入名字：>");
    scanf("%s", pc->data[pc->sz].name);
    printf("请输入年龄：>");
    scanf("%d", &(pc->data[pc->sz].age));
    printf("请输入性别：>");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入电话：>");
    scanf("%s", pc->data[pc->sz].tele);
    printf("请输入地址：>");
    scanf("%s", pc->data[pc->sz].addr);

    pc->sz++;
    printf("增加联系人成功\n");
}

//显示通讯录
void ShowContact(const Contact *pc) {
    assert(pc);
    //打印标题
    printf("%-10s\t%-4s\t%-5s\t %-20s\t %-30s\n", "名字", "年龄", "性别", "电话", "地址");
    //打印数据
    for (int i = 0; i < pc->sz; ++i) {
        printf("%-10s\t%-4d\t%-5s\t %-20s\t %-30s\n",
               pc->data[i].name,
               pc->data[i].age,
               pc->data[i].sex,
               pc->data[i].tele,
               pc->data[i].addr);
    }
}

//根据名字找人

int FindByName(const Contact *pc, char name[MAX_NAME]) {
    assert(pc);
    for (int i = 0; i < pc->sz; ++i) {
        if (strcmp(name, pc->data[i].name) == 0) {
            //找到了
            return i;
        }
    }
    //没找到
    return -1;

}

//删除通讯录的某个人
void DelContact(Contact *pc) {
    assert(pc);
    if (pc->sz == 0) {
        printf("通讯录为空，无需删除\n");
        return;
    }
    char name[MAX_NAME];
    printf("请输入要删除的人的名字：>");
    scanf("%s", name);
    //找到要删除的人的位置
//    int del_pos = 0;
//    int flag = 0;
//    for (int i = 0; i < pc->sz; ++i) {
//        if (strcmp(name, pc->data[i].name) == 0) {
//            //找到了
//            del_pos = i;
//            flag = 1;
//            break;
//        }
//    }
//    if (0 == flag) {
//        printf("要删除的人不存在\n");
//        return;
//    }
    int del_pos = FindByName(pc, name);
    if (-1 == del_pos) {
        printf("要删除的人不存在\n");
        return;
    }
    //删除坐标为del_pos的联系人
    for (int i = del_pos; i < pc->sz - 1; i++) {
        //del_pos后面的联系人前移
        pc->data[i] = pc->data[i + 1];
    }
    pc->sz--;
    printf("成功删除联系人\n");
}

//查找指定联系人
void SearchContact(const Contact *pc) {
    assert(pc);
    char name[MAX_NAME];
    printf("请输入要查找的人的名字：>");
    scanf("%s", name);
    int pos = FindByName(pc, name);
    if (-1 == pos) {
        printf("没有这个人\n");
        return;
    } else {
        //打印数据
        printf("%-10s\t%-4d\t%-5s\t %-20s\t %-30s\n",
               pc->data[pos].name,
               pc->data[pos].age,
               pc->data[pos].sex,
               pc->data[pos].tele,
               pc->data[pos].addr);
    }
}

//修改指定联系人
void ModifyContact(Contact *pc) {
    assert(pc);
    char name[MAX_NAME];
    printf("请输入要修改的人的名字：>");
    scanf("%s", name);
    int pos = FindByName(pc, name);
    if (-1 == pos) {
        printf("没有这个人\n");
        return;
    } else {
        printf("请输入名字：>");
        scanf("%s", pc->data[pos].name);
        printf("请输入年龄：>");
        scanf("%d", &(pc->data[pos].age));
        printf("请输入性别：>");
        scanf("%s", pc->data[pos].sex);
        printf("请输入电话：>");
        scanf("%s", pc->data[pos].tele);
        printf("请输入地址：>");
        scanf("%s", pc->data[pos].addr);
        printf("修改成功\n");
    }
}