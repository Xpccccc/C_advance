//
// Created by 徐鹏 on 2023/7/24.
//
//
// Created by 徐鹏 on 2023/7/22.
//

#include "contact.h"

//初始化通讯录

//静态版本
//void InitContact(Contact *pc) {
//    assert(pc);
//    memset(pc->data, 0, sizeof(pc->data));
//    pc->sz = 0;
//}

int CheckCapacity(Contact *);

//加载通讯录
void LoadContact(Contact *pc){
    assert(pc);
    FILE * pf = fopen("contact.dat","rb");
    if(NULL==pf){
        perror("LoadContact");
        return;
    }
    //读文件
    PeoInfo temp = {0};
    while(fread(&temp,sizeof (PeoInfo),1,pf)){
        CheckCapacity(pc);
        pc->data[pc->sz] = temp;
        pc->sz++;
    }
    fclose(pf);
    pf = NULL;
}

//动态版本
void InitContact(Contact *pc) {
    assert(pc);
    pc->data = (PeoInfo *) malloc(DEFAULT_SIZE * sizeof(PeoInfo));
    if (NULL == pc->data) {
        perror("InitContact");
        return;
    }
    pc->sz = 0;
    pc->capacity = DEFAULT_SIZE;
    LoadContact(pc);
}


//静态版本
//增加通讯录
//void AddContact(Contact *pc) {
//    assert(pc);
//    if (pc->sz == MAX) {
//        printf("该通讯录已满\n");
//        return;
//    }
//    printf("请输入名字：>");
//    scanf("%s", pc->data[pc->sz].name);
//    printf("请输入年龄：>");
//    scanf("%d", &(pc->data[pc->sz].age));
//    printf("请输入性别：>");
//    scanf("%s", pc->data[pc->sz].sex);
//    printf("请输入电话：>");
//    scanf("%s", pc->data[pc->sz].tele);
//    printf("请输入地址：>");
//    scanf("%s", pc->data[pc->sz].addr);
//
//    pc->sz++;
//    printf("增加联系人成功\n");
//}

int CheckCapacity(Contact *pc) {
    if (pc->sz == pc->capacity) {
        PeoInfo *ptr = (PeoInfo *) realloc(pc->data, (pc->capacity + INC_SIZE) * sizeof(PeoInfo));
        if (ptr == NULL) {
            perror("CheckCapacity");
            return 0;//增容失败返回0
        } else {
            pc->data = ptr;
            pc->capacity += INC_SIZE;
            printf("增容成功\n");
            return 1;//增容返回1
        }
    }
    return 1;//不需要增容返回1
}


//动态版本
void AddContact(Contact *pc) {
    assert(pc);
    if (0 == CheckCapacity(pc)) {
        return;
    }
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

void DestroyContact(Contact *pc) {
    assert(pc);
//    if (0 == pc->sz) {
//        printf("通讯录已为空,无需清空\n");
//        return;
//    }
//    InitContact(pc);//用初始化来清空
//    printf("已清空通讯录\n");

    free(pc->data);
    pc->data = NULL;
    pc->sz = 0;
    pc->capacity = 0;
    printf("已清空通讯录\n");
}

//排序通讯录
void SortContact(Contact *pc) {
    assert(pc);
    if (0 == pc->sz) {
        printf("通讯录为空，无需排序\n");
        return;
    }

    //按名字排序,冒泡排序
    for (int i = 0; i < pc->sz - 1; ++i) {
        for (int j = 0; j < pc->sz - 1 - i; ++j) {
            if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0) {
                PeoInfo temp = pc->data[j];
                pc->data[j] = pc->data[j + 1];
                pc->data[j + 1] = temp;
            }
        }
    }
    printf("排序完成\n");
}

//保存通讯录
void SaveContact(Contact *pc){
    assert(pc);
    FILE* pf = fopen("contact.dat","wb");
    if(NULL == pf){
        perror("SaveContact");
        return;
    }
    //写数据
    for (int i = 0; i < pc->sz; ++i) {
        fwrite(pc->data+i,sizeof (PeoInfo),1,pf);
    }

    //关闭文件
    fclose(pf);
    pf =NULL;
}