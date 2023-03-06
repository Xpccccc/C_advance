#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//29、编写一个程序,将字符数组s2中的全部字符拷贝到字符数组s1中,不用strcpy函数。
// 拷贝时，’\0’也要拷贝过去，’\0’后面的字符不拷贝。//故用s2.strlen();
int main() {
    char s2[100] = {0};
    gets(s2);
    int len = strlen(s2);
    char *s1 = (char *) malloc(sizeof(char) * len + 1);//加上\0共len+1个元素
    for (int i = 0; i < len; ++i) {
        s1[i] = s2[i];
    }
    s1[len] = '\0';
    for (int i = 0; i < len; ++i) {
        printf("%c", s1[i]);
    }
    return 0;
}
