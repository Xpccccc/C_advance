//
// Created by 徐鹏 on 2023/7/22.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>


#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H

#endif //CONTACT_CONTACT_H

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 20
#define MAX_ADDR 30

//通讯录个人信息
typedef struct PeoInfo {
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR]
} PeoInfo;

//通讯录
typedef struct Contact {
    PeoInfo data[MAX];//通讯录容量
    int sz;//当前通讯录指向的地方
} Contact;

//初始化通讯录
void InitContact(Contact *pc);
//增加通讯录
void AddContact(Contact *pc);
//显示通讯录
void ShowContact(const Contact *pc);
//删除通讯录的某个人
void DelContact(Contact *pc);
//查找指定联系人
void SearchContact(const Contact *pc);
//修改指定联系人
void ModifyContact( Contact *pc);