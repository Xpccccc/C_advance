
//169. 多数元素
int majorityElement(int *nums, int numsSize) {
    int candidate = nums[0];//指向最多的元素的候选
    int count = 1;//记录当前元素的得票数

    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] == candidate) {
            count++;//元素相同就投票
        } else {
            //不相同就反对投票
            count--;//若count<0得给新候选让位
            if (count < 0) {
                candidate = nums[i];
                count = 1;//重置
            }
        }
    }
    //候选人一定是总得票数大于1的，m代表投票数，n代表反对数，m-n>1,因为多数元素大于n/2,所以投票数比反对数大
    return candidate;
}