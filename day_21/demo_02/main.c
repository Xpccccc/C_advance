#include <stdio.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};


struct Node *BuyListNode(int x) {
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->val = x;
    node->next = NULL;
    node->random = NULL;
    return node;
}

struct Node *Find_pos(struct Node *phead, int x) {
    while (phead) {
        if (phead->val == x) {
            return phead;
        } else {
            phead = phead->next;
        }
    }
    //没找到
    return NULL;
}

struct Node *copyRandomList(struct Node *head) {
    //random就相当于prev
    //创建一个带头结点
    struct Node *plist = (struct Node *) malloc(sizeof(struct Node));
    plist->next = NULL;
    plist->random = NULL;
    struct Node *cur = head;
    struct Node *tail = plist;//便于尾插
    //先复制链表
    while (cur) {
        struct Node *newnode = BuyListNode(cur->val);
        cur = cur->next;
        //尾插
        tail->next = newnode;
        tail = tail->next;
    }
    cur = head;//重置老链表当前位置；
    struct Node *copy_cur = plist->next;//记录新链表当前位置
    while (cur) {
        //把新链表的random指向复制过来
        //通过老链表random指向的结点的值去新链表找出来该值对应的地址
        copy_cur->random = Find_pos(head, cur->random->val);
        cur = cur->next;
        copy_cur = copy_cur->next;
    }
    tail = plist->next;
    free(plist);
    return tail;
}

int main() {
//    struct Node *n1 = (struct Node *) malloc(sizeof(struct Node));
//    struct Node *n2 = (struct Node *) malloc(sizeof(struct Node));
//    n1->val = 1;
//    n2->val = 2;
//    n1->next = n2;
//    n1->random = Find_pos(n1, 2);
//    n2->next = NULL;
//    n2->random = Find_pos(n1, 2);
//    struct Node *plist = copyRandomList(n1);//复制后的链表



}

