/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//21. 合并两个有序链表

struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    //链表1为空，返回链表2
    if (!list1)
        return list2;
    //链表2为空，返回链表1
    if (!list2)
        return list1;
    struct ListNode *head = NULL, *tail = NULL;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            //以list1返回
            if (tail == NULL) {
                head = tail = list1;
            } else {
                tail->next = list1;
                tail = tail->next;
            }

            list1 = list1->next;
        } else {
            //以list2返回
            if (tail == NULL) {
                head = tail = list2;
            } else {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }
    if (list1)
        tail->next = list1;
    if (list2)
        tail->next = list2;
    return head;
}