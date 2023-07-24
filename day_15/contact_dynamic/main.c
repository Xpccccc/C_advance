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
                DestroyContact(&con);
                printf("退出通讯录\n");
                break;
            default:
                printf("输入有误，请重新输入!\n");
                break;

        }
    } while (input);
}


//动态版本通讯录
int main() {
    test();
    return 0;
}
