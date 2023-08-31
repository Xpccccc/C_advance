/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param numbers int整型一维数组 
 * @param numbersLen int numbers数组长度
 * @param target int整型 
 * @return int整型一维数组
 * @return int* returnSize 返回数组行数
 */

//NC61 两数之和
int *twoSum(int *numbers, int numbersLen, int target, int *returnSize) {
    // write code here
    int *ret = (int *) malloc(sizeof(int) * 2);
    for (int i = 0; i < numbersLen; ++i) {

        if (numbers[i] > target + 10)//样例中数据>=-10，所以如果数据大于target+10则该数据不可能为目标数据，可以跳过循环
        {
            continue;
        }
        for (int j = i + 1; j < numbersLen; ++j) {
            if (numbers[i] + numbers[j] == target) {
                ret[0] = i + 1;
                ret[1] = j + 1;
                *returnSize = 2;
                return ret;
            }
        }
    }
    //没找到
    *returnSize = 0;
    return NULL;
}