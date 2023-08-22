
//JZ65 不用加减乘除做加法
int Add(int num1, int num2) {
    // write code here
    if (num2 == 0)
        return num1;
    return Add(num1 ^ num2, (num1 & num2) << 1);
}