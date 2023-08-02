/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//206. 反转链表
struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL)
        return head;
    //头插法
    struct ListNode *p = head, *newhead = NULL;//p记录head的后继，防止断链
    while (head) {
        p = head->next;//p记录head的后继，防止断链
        head->next = newhead;
        newhead = head;
        head = p;
    }
    return newhead;
}