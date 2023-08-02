/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//876. 链表的中间结点
struct ListNode *middleNode(struct ListNode *head) {
    //快慢指针
    struct ListNode *low = head, *fast = head;
    while (fast && fast->next) {
        low = low->next;
        fast = fast->next->next;
    }
    return low;
}