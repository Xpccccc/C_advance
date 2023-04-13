#include <stdio.h>

//指针运算
int main() {
    char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char **cp[] = {c + 3, c + 2, c + 1, c};//cp的元素是二级指针
    char ***cpp = cp;//那cp首元素地址就是三级指针,那cpp就是cp的首元素地址
    printf("%s\n", **++cpp);//POINT
    printf("%s\n", *--*++cpp + 3);//ER
    printf("%s\n", *cpp[-2] + 3);//ST
    printf("%s\n", cpp[-1][-1] + 1);//*(*(cpp-1)-1) + 1  ,EW

    return 0;
}
