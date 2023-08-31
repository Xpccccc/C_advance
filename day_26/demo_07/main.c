

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//面试题 16.15. 珠玑妙算
int *masterMind(char *solution, char *guess, int *returnSize) {
    int *answer = (int *) malloc(sizeof(int) * 2);
    memset(answer, 0, sizeof(int) * 2);
    *returnSize = 2;
    for (int i = 0; i < 4; ++i) {
        if (solution[i] == guess[i]) {
            answer[0]++;//猜中位置
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (guess[i] == solution[j]) {
                solution[j] = 0;//防止重复,碰到一次和guess[i]相同的元素，就在solution里面少出现一次该元素，下一次在guess[i]中就不会出现和前一次一样的元素重复对比
                answer[1]++;//这里算上了猜中的，后面得减掉
                break;
            }
        }
    }
    answer[1] -= answer[0];
    return answer;
}
