#include <stdio.h>
#include <tgmath.h>

//7、求Sn=a+aa+aaa+…+aa…aaa（有n个a）之值，其中a是一个数字。例如：
//2+22+222+2222+22222（n=5），n由键盘输入。
int main() {
    int n = 0;
    int num = 0;
    int sum = 0;
    scanf("%d", &n);
    int i = 0;
    while (i < n) {
        num += 2 * pow(10, i);
        sum += num;
        i++;
    }
    printf("%d\n", sum);
    return 0;
}
