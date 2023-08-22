
//JZ65 不用加减乘除做加法
int Add(int num1, int num2) {
    // write code here
    //不进位的情况
    if (num2 == 0)
        return num1;
    //进位的情况
    return Add(num1 ^ num2, (num1 & num2) << 1);//num1 ^ num2得出除掉进位以外的位的和，(num1 & num2) << 1得出进位或者不进位的情况
}