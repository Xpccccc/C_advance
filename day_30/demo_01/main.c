#include <stdio.h>
#include <stdlib.h>


//二叉树
typedef struct BTNode {
    struct BTNode *left;
    struct BTNode *right;
    int val;
} BTNode;

#include "Queue.h"

BTNode *BuyBTNode(int x) {
    BTNode *newNode = (BTNode *) malloc(sizeof(BTNode));
    if (newNode == NULL) {
        perror("malloc error");
        exit(-1);
    }
    newNode->val = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//前序遍历
void PrevOrder(BTNode *root) {
    if (root == NULL) {
        printf("%s ", "NULL");
        return;
    }
    printf("%d ", root->val);
    PrevOrder(root->left);
    PrevOrder(root->right);
}

//中序遍历
void InOrder(BTNode *root) {
    if (root == NULL) {
        printf("%s ", "NULL");
        return;
    }
    InOrder(root->left);
    printf("%d ", root->val);
    InOrder(root->right);
}

//后序遍历
void PostOrder(BTNode *root) {
    if (root == NULL) {
        printf("%s ", "NULL");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->val);
}

//层序遍历
void LevelOrder(BTNode *root) {
    Que q;
    QueInit(&q);
    QuePush(&q, root);
    while (!QueEmpty(&q)) {
        BTNode *front = QueFront(&q);
        printf("%d ", front->val);
        if (front->left)
            QuePush(&q, front->left);
        if (front->right)
            QuePush(&q, front->right);
        QuePop(&q);
    }
    QueDestroy(&q);
}

//二叉树结点个数
int BinarySize(BTNode *root) {
    if (root == NULL)
        return 0;
    return BinarySize(root->left) + BinarySize(root->right) + 1;
}

//二叉树的叶子结点个数
int BinaryLeafSize(BTNode *root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return BinaryLeafSize(root->left) + BinaryLeafSize(root->right);
}

//二叉树每层结点的个数
int BinaryLayerSize(BTNode *root, int k) {
    if (root == NULL) //当前结点指向为空则返回0 也就是当前结点为子树的时候指向空
        return 0;
    if (k == 1) //到了要求的第k层了
        return 1;
    //一直左右找当k = 1的结点，找到就加1  也就是找相对于某一层为第1层的结点
    //第3层相对于第1层就是第3层 ，第3层相对于第2层就是第2层，第3层相对于第3层就是第1层 也就是找相对于某一层为第1层的结点
    //也就是求k-1层左右结点的个数
    //比如求第2层的结点个数 ，就是求第1层结点的左右结点的个数 (其中走到第2层的时候 k=1)
    //比如求第3层的结点个数 ，就是求第2层结点的左右结点的个数 (其中走到第3层的时候 k=1)
    //比如求第4层的结点个数 ，就是求第3层结点的左右结点的个数 (其中走到第4层的时候 k=1)
    return BinaryLayerSize(root->left, k - 1) + BinaryLayerSize(root->right, k - 1);
}

//二叉树查找值为x的结点
BTNode *TreeFind(BTNode *root, int x) {
    if (root == NULL)
        return NULL;

    if (root->val == x)
        return root;

    BTNode *ret = TreeFind(root->left, x);
    if (ret != NULL)
        return ret;
    ret = TreeFind(root->right, x);
    if (ret != NULL)
        return ret;
    return NULL;
}

int main() {
    BTNode *Node1 = BuyBTNode(1);
    BTNode *Node2 = BuyBTNode(2);
    BTNode *Node3 = BuyBTNode(3);
    BTNode *Node4 = BuyBTNode(4);
    BTNode *Node5 = BuyBTNode(5);
    BTNode *Node6 = BuyBTNode(6);
    Node1->left = Node2;
    Node1->right = Node3;
    Node2->left = Node4;
    Node2->right = Node5;
    Node3->left = Node6;
    //前序遍历
    PrevOrder(Node1);
    printf("\n");
    //中序遍历
    InOrder(Node1);
    printf("\n");
    //后序遍历
    PostOrder(Node1);
    printf("\n");
    printf("%d\n", BinarySize(Node1));
    printf("%d\n", BinaryLeafSize(Node1));
    printf("%d\n", BinaryLayerSize(Node1, 2));
    LevelOrder(Node1);
    return 0;
}
