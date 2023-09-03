#include <stdio.h>

//WY49 数对

//解法：
//
//题目要求：1<= x <= n     1<= y <= n       x%y>=k
//        由于x%y的余数要>=k, 故而y最终确定的取值范围是k+1~n
//        why:  若y是k，则x%y的余数的的值最大是k-1
//
//a. 将x划分为几个区间：
//
//[1,    2,    ..., y]
//[y+1,  y+2,  ..., 2y]
//[2y+1, 2y+2, ..., 3y]
//...
//[ty+1, ty+2, ..., n]
//
//以下是x的所有取值：1~n
//
//1	2	        ……	k	    ……	y-1	    y
//y+1	y+2	    ……	y+k	    ……	2y-1	2y
//2y+1	2y+2	……	2y+k	……	3y-1	3y
//3y+1	3y+2	……	3y+k	……	4y-1	4y
//ty+1	ty+2	……	ty+k	……	n
//
//        x%y的余数：
//
//1	2	……	k	……	y-1	0
//1	2	……	k	……	y-1	0
//1	2	……	k	……	y-1	0
//1	2	……	k	……	y-1	0
//1	2	……	k	……	n%y(余数，也就是相对于y多出来的部分)
//
//        由表可知
//完整区间（除了最后一个区间）符合题意 余数>=k的值的范围：k~y-1
//
//即y-1-k+1 = y-k
//
//        eg. 区间1~3的个数：3-1+1=3
//
//故而：只要是完整区间，符合条件的个数是y-k
//
//最后一个区间 符合题意 余数>=k的值的范围：k~n%y
//
//即n%y-k+1
//
//故而：最后一个区间符合条件的个数是n%y-k+1
//不符合条件就是 0

int main() {
    long n = 0;
    int k = 0;
    long count = 0;
    scanf("%ld%d", &n, &k);
    if (k == 0) {
        count = n * n;//0满足所有组合,注意 若 n 的类型是 int ，那int * int 得到的是 int ，可能会溢出 ，所以 n 的类型用 long
    } else {
        //y最终确定的取值范围是k+1~n
        for (int y = k + 1; y <= n; ++y) {
            //完整区间（除了最后一个区间）符合题意 余数>=k的值的范围：k~y-1 ,个数为 y-k
            //不完整区间（最后一行）符合题意 余数>=k的值的范围：k~n%y ，个数为 n%y-k+1。不符合题意的 那就为0，既不存在
            //完整区间个数 = n/y
            count += (n / y) * (y - k) + ((n % y < k) ? 0 : (n % y - k + 1));
        }
    }

    printf("%lld", count);
    return 0;
}