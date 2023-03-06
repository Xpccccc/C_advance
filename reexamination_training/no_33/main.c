#include <stdio.h>
#include <tgmath.h>

//32、写一个判断素数的函数，在主函数输入一个整数，输出是否是素数的消息。
int is_sushu(int n){
    for (int i = 2; i <= sqrt(n); ++i) {
        if(n%i == 0)
            return 0;//不是素数
    }
    return 1;//判断完是素数
}
int main() {
    int n = 0;
    scanf("%d",&n);
    if(1 == is_sushu(n))
        printf("是素数\n");
    else
        printf("不是素数\n");
    return 0;
}
