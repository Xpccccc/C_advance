#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


// 先快慢指针找到中间节点；
// 原地反转后半部分链表；
// 依次比较前半部分链表与反转后的后半部分链表；
// 还原反转的链表；
bool isPalindrome(struct ListNode *head) {
    // 先快慢指针找到中间节点；
    struct ListNode *low = head, *fast = head;
    //如果只有一个结点，直接返回true
    if (!head->next)
        return true;
    //如果只有两个结点，只需要比较第一个结点的值和第二个结点的值是否相等
    if (!head->next->next) {
        if (head->val == head->next->val) {
            return true;
        } else {
            return false;
        }
    }
    //两个结点以上
    fast = fast->next;//使得在结点个数为偶数的时候low在中位数的两个里面的前一个位置，比如 0—>1->2->3 ,low指向2,以便于下面逆置算法（带头结点的头插）
    while (fast && fast->next) {
        low = low->next;
        fast = fast->next->next;
    }
    //找到中间结点low
    //从low开始逆置,采用头插法
    struct ListNode *p = low->next, *q = low, *r = NULL;//q记录中点位置，r用来记录p的后驱，防止断链
    // 原地反转后半部分链表；
    low->next = NULL;
    while (p) {
        r = p->next;
        p->next = low->next;
        low->next = p;
        p = r;
    }
    // 依次比较前半部分链表与反转后的后半部分链表；
    q = q->next;//中点往后一个的位置，准备与前面的元素逐个对比
    while (q) {
        if (head->val != q->val) {
            return false;
        } else {
            head = head->next;
            q = q->next;
        }
    }
    // 还原反转的链表；
    //从中点处继续采用头插法就行
    return true;
}

//027. 回文链表(剑指 Offer II )
int main() {
    struct ListNode *n1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *n2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *n3 = (struct ListNode *) malloc(sizeof(struct ListNode));
    struct ListNode *n4 = (struct ListNode *) malloc(sizeof(struct ListNode));
//    struct ListNode *n5 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n1->val = 1;
    n2->val = 1;
    n3->val = 2;
    n4->val = 3;
//    n5->val = 1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
//    n4->next = n5;
    n4->next = NULL;
    bool ret = isPalindrome(n1);
    printf("%d", ret);
    return 0;
}
