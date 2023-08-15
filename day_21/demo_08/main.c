
//面试题 05.06. 整数转换
int convertInteger(int A, int B) {
    int count = 0;//记录需要改变的位数
    //2147483647 = 2^31-1
    for (int i = 0; i < 32; ++i) {
        count += ((A >> i) & 1) ^ ((B >> i) & 1);
    }
    return count;
}