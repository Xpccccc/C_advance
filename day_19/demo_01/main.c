/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
#include <cstdlib>


//CM11 链表分割
class Partition{
        public:
        ListNode * partition(ListNode * pHead, int x) {
            // write code here
            //创建两个表头
            ListNode *ghead = pHead, *gtail, *lhead, *ltail;
            ghead = gtail = (ListNode *) malloc(sizeof(ListNode));
            lhead = ltail = (ListNode *) malloc(sizeof(ListNode));

            ListNode *cur = pHead;
            while (cur) {
                if (cur->val < x) {
                    ltail->next = cur;
                    ltail = ltail->next;
                } else {
                    gtail->next = cur;
                    gtail = gtail->next;
                }
                cur = cur->next;
            }
            //连接起来，l的尾接g的头
            ltail->next = ghead->next;
            //防止出现环
            gtail->next = NULL;
            ListNode *lhead_r = lhead->next;
            free(lhead);
            lhead = lhead_r;
            return lhead;
        }
};