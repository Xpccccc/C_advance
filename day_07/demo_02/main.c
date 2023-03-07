#include <stdio.h>

int Add(int x, int y) {
    return x + y;
}

int Sub(int x, int y) {
    return x - y;
}

int Mul(int x, int y) {
    return x * y;
}

int Div(int x, int y) {
    return x / y;
}

//回调函数
void Cal(int(*pf)(int, int)) {
    int x = 0;
    int y = 0;
    printf("请输入两个操作数:");
    scanf("%d %d", &x, &y);
    int ret = pf(x, y);
    printf("%d\n", ret);
}

void menu() {
    printf("****************************\n");
    printf("*****  1.Add   2.Sub  ******\n");
    printf("*****  3.Mul   4.Div  ******\n");
    printf("*****      0.Exit     ******\n");
    printf("****************************\n");
}

//回调函数
int main() {
    int input = 0;
    do {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch (input) {
            case 0:
                printf("不玩了\n");
                break;
            case 1:
                Cal(Add);
                break;
            case 2:
                Cal(Sub);
                break;
            case 3:
                Cal(Mul);
                break;
            case 4:
                Cal(Div);
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    } while (input);
    return 0;
}
