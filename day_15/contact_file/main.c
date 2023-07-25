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
                SaveContact(&con);
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
//在之前的通讯录上增加两个函数，实现数据可以保存到文件，也可以从文件中加载数据。
//a. 添加一个函数，在退出通讯录的时候把信息到保存到文件中
//b. 添加一个函数，在通讯录打开的时候，可以把文件中的信息加载到通讯录中
int main() {
    test();
    return 0;
}
