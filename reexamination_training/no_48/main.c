#include <stdio.h>
//47、请设计输出实数的格式，包括：⑴一行输出一个实数；⑵一行内输出两个实
//数；⑶一行内输出三个实数。实数用"6.2f"格式输出。

#define PR1(a) printf("%6.2f\n",a)
#define PR2(a) printf("%6.2f%6.2f\n",a,a)
#define PR3(a) printf("%6.2f%6.2f%6.2f\n",a,a,a)

int main() {
    float a = 0;
    scanf("%f", &a);
    PR1(a);
    PR2(a);
    PR3(a);
    return 0;
}
