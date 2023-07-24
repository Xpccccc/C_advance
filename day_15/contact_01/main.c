#include "contact.h"


void menu() {
    printf("***********************************\n");
    printf("******  1.add      2.del     ******\n");
    printf("******  3.search   4.modify  ******\n");
    printf("******  5.show     6.destroy ******\n");
    printf("******  7.sort     0.exit    ******\n");
    printf("***********************************\n");
}

enum OPTION {
    EXIT,
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SHOW,
    DESTROY,
    SORT,
};

void test() {
    int input = 0;
    //首先得有通讯录
    Contact con;
    InitContact(&con);//初始化通讯录
    do {
        menu();
        printf("请选择：>");
        scanf("%d", &input);
        switch (input) {
            case ADD:
                AddContact(&con);
                break;
            case DEL:
                DelContact(&con);
                break;
            case SEARCH:
                SearchContact(&con);
                break;
            case MODIFY:
                ModifyContact(&con);
                break;
            case SHOW:
                ShowContact(&con);
                break;
            case DESTROY:
                DestroyContact(&con);
                break;
            case SORT:
                //按名字排序
                SortContact(&con);
                break;
            case EXIT:
                printf("退出通讯录\n");
                break;
            default:
                printf("输入有误，请重新输入!\n");
                break;

        }
    } while (input);
}

//实现一个通讯录；
//通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
//提供方法：
//添加联系人信息
//删除指定联系人信息
//查找指定联系人信息
//修改指定联系人信息
//显示所有联系人信息
//清空所有联系人
//以名字排序所有联系人


int main() {
    test();
    return 0;
}
