/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//141. 环形链表
bool hasCycle(struct ListNode *head) {
    //快慢指针，若有环快指针一定会追上慢指针
    struct ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {//存在环
            return true;
        }
    }
    return false;//不存在环
}