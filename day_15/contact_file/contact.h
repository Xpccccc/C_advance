//
// Created by 徐鹏 on 2023/7/24.
//

#ifndef CONTACT_FILE_CONTACT_H
#define CONTACT_FILE_CONTACT_H

#endif //CONTACT_FILE_CONTACT_H
//
// Created by 徐鹏 on 2023/7/24.
//

#ifndef CONTACT_DYNAMIC_CONTACT_H
#define CONTACT_DYNAMIC_CONTACT_H

#endif //CONTACT_DYNAMIC_CONTACT_H
//
// Created by 徐鹏 on 2023/7/22.
//

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 20
#define MAX_ADDR 30
#define DEFAULT_SIZE 3
#define INC_SIZE 2

//通讯录个人信息
typedef struct PeoInfo {
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR]
} PeoInfo;

//静态通讯录
//typedef struct Contact {
//    PeoInfo data[MAX];//通讯录容量
//    int sz;//当前通讯录指向的地方
//} Contact;

typedef struct Contact {
    PeoInfo* data;//指向存放数据的空间
    int sz;//当前通讯录有效人数
    int capacity;//通讯录容量
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
void ModifyContact(Contact *pc);

//清空通讯录
void DestroyContact(Contact *pc);

//排序通讯录
void SortContact(Contact *pc);

//保存通讯录
void SaveContact(Contact *pc);
