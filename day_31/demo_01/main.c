#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
    struct BTNode *left;
    struct BTNode *right;
    char val;
} BTNode;

BTNode *CreateTree(char *str, int *i) {
    if (*(str + *i) == '#') {
        (*i)++;
        return NULL;
    }
    BTNode *root = (BTNode *) malloc(sizeof(BTNode));
    root->val = *(str + *i);
    (*i)++;
    root->left = CreateTree(str, i);
    root->right = CreateTree(str, i);
    return root;
}

void inOrder(BTNode *root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%c ", root->val);
    inOrder(root->right);
}

//KY11 二叉树遍历
int main() {
    char str[100] = {0};
    scanf("%s", str);
    int j = 0;
    BTNode *root = CreateTree(str, &j);
    inOrder(root);
    return 0;
}