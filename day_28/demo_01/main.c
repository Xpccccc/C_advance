#include <stdio.h>
#include <stdlib.h>

struct S {
    int a;
    float b;
};

struct Stu {
    int a;
    float b;
    char str[10];
};

int main() {
//    FILE *pf = fopen("./data.txt","w");//写
//    fputc('a',pf);
//    fputc('b',pf);
//    fputc('c',pf);
//    FILE *pf = fopen("./data.txt", "r");//读
////    int ch = fgetc(stdin);//从键盘读
//    int ch = fgetc(pf);//从文件读
//    printf("%c", ch);
//    ch = fgetc(pf);
//    printf("%c", ch);
//    ch = fgetc(pf);
//    printf("%c", ch);

//    FILE *pf = fopen("./data.txt", "w");
//    if (NULL == pf) {
//        perror("fopen error");
//        exit(-1);
//    }
//    fputs("hello ", pf);//写一行
//    fputs("hh\n", pf);
//    fputs("www", pf);

//    FILE *pf = fopen("./data.txt", "r");
//    if (NULL == pf) {
//        perror("fopen error");
//        exit(-1);
//    }
//    char arr[10] = {0};
//    fgets(arr, 10, pf);//读一行
//    printf("%s\n", arr);
//    fgets(arr, 10, pf);
//    printf("%s\n", arr);
//    fgets(arr, 10, pf);
//    printf("%s\n", arr);


    //格式化读写
    //写
//    FILE *pf = fopen("./data.txt", "w");
//    if (NULL == pf) {
//        perror("fopen error");
//        exit(-1);
//    }
//    struct S s = {1, 2.2};
//    fprintf(pf, "%d %f", s.a, s.b);

//    //读
//    FILE *pf = fopen("./data.txt", "r");
//    if (NULL == pf) {
//        perror("fopen error");
//        exit(-1);
//    }
//    struct S s = {0};
//    fscanf(pf, "%d %f", &s.a, &s.b);
//    printf("%d %f", s.a, s.b);
//    fclose(pf);
//    pf = NULL;


//    char arr[30] = {0};
//    struct Stu st = {1, 2.3, "hhhh"};
//    struct Stu tmp = {0};
//    sprintf(arr, "%d %f %s", st.a, st.b, st.str);//将格式化的数据转换成字符串
//    printf("%s\n", arr);
//    sscanf(arr, "%d %f %s", &tmp.a, &tmp.b, tmp.str);//从字符串中提取格式化的数据
//    printf("%d %f %s\n", tmp.a, tmp.b, tmp.str);
//    return 0;

    //二进制写
//    FILE *pf = fopen("./data.txt", "wb");
//    if (NULL == pf) {
//        perror("fopen error");
//        exit(-1);
//    }
//    struct S s = {1, 2.2};
//    fwrite(&s, sizeof(struct S), 1, pf);
//    fclose(pf);
//    pf = NULL;

    //二进制读
    FILE *pf = fopen("./data.txt", "rb");
    if (NULL == pf) {
        perror("fopen error");
        exit(-1);
    }
    struct S s = {0};
    fread(&s, sizeof(struct S), 1, pf);
    printf("%d %f\n", s.a, s.b);
    fclose(pf);
    pf = NULL;
}
