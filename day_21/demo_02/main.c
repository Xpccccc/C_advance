/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

//138. 复制带随机指针的链表


// 1、创建一个新结点链接到老结点后面

// 2、复制random指向：copy->random = cur->random->next

// 3、链接新结点链表，恢复老结点链表
struct Node *copyRandomList(struct Node *head) {
    struct Node *cur = head;
    // 1、创建一个新结点链接到老结点后面
    while (cur) {
        struct Node *next = cur->next;
        struct Node *copy = (struct Node *) malloc(sizeof(struct Node));
        copy->val = cur->val;
        //插入
        cur->next = copy;
        copy->next = next;
        //后移
        cur = next;
    }

    // 2、复制random指向：copy->random = cur->random->next
    cur = head;
    while (cur) {
        struct Node *copy = cur->next;
        //插入
        if (cur->random == NULL) {
            copy->random = NULL;
        } else {
            copy->random = cur->random->next;
        }
        //后移
        cur = copy->next;
    }

    // 3、链接新结点链表，恢复老结点链表
    cur = head;
    struct Node *copy_head = NULL;
    struct Node *copy_tail = NULL;

    while (cur) {
        struct Node *copy = cur->next;
        struct Node *next = copy->next;// cur的后驱
        //尾插
        if (copy_tail == NULL) {
            copy_tail = copy_head = copy;
        } else {
            copy_tail->next = copy;
            copy_tail = copy_tail->next;
        }
        //恢复新链表
        cur->next = next;

        //后移
        cur = next;
    }
    return copy_head;
}