/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//203. 移除链表元素
struct ListNode *removeElements(struct ListNode *head, int val) {
    struct ListNode *pre = head, *del = head;//pre记录要删除结点的前驱
    if (head == NULL)
        return head;
    while (del) {
        if (del->val != val) {
            pre = del;
            del = del->next;
        } else {
            if (del == head) {
                //头删
                head = del->next;
                free(del);
                del = head;
            } else {
                pre->next = del->next;
                free(del);
                del = pre->next;
            }

        }
    }
    return head;
}