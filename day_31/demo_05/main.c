/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param n int整型 
 * @param m int整型 
 * @return int整型
 */

//NC132 环形链表的约瑟夫问题
typedef struct ListNode ListNode;

ListNode *buyNode(int x) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->next = NULL;
    node->val = x;
    return node;
}

ListNode *creadList(int n) {
    ListNode *phead, *ptail;
    phead = ptail = buyNode(1);
    int i = 2;
    while (i <= n) {
        ptail->next = buyNode(i++);
        ptail = ptail->next;
    }
    ptail->next = phead;
    return phead;
}


int ysf(int n, int m) {
    // write code here
    ListNode *head = creadList(n);
    int i = 1;
    ListNode *prev = NULL;
    ListNode *cur = head;
    while (cur != cur->next) {
        if (i == m) {
            prev->next = cur->next;
            free(cur);
            cur = prev->next;
            i = 1;//重新计算
        } else {
            prev = cur;
            cur = cur->next;
            i++;
        }
    }
    return cur->val;
}