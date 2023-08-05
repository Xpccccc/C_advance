/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//160. 相交链表
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    //先找出到底谁长，长的先走，先走走比短的多出来的长度
    int len_A = 0, len_B = 0;
    struct ListNode *pa = headA, *pb = headB;
    while (pa) {
        pa = pa->next;
        len_A++;
    }
    while (pb) {
        pb = pb->next;
        len_B++;
    }
    //链表长度差值
    int k = len_A > len_B ? (len_A - len_B) : (len_B - len_A);
    //重置
    pa = headA;
    pb = headB;
    if (len_A > len_B) {
        while (k) {
            pa = pa->next;
            k--;
        }
    } else {
        while (k) {
            pb = pb->next;
            k--;
        }
    }
    while (pa) {
        if (pa == pb) {
            //相等返回地址
            return pa;
        } else {
            //不相等则一起同步后移
            pa = pa->next;
            pb = pb->next;
        }
    }
    //没有公共交点
    return NULL;
}