#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q != NULL)
        return false;
    if (q == NULL && p != NULL)
        return false;
    if (q == NULL && p == NULL)
        return true;
    if (q->val != p->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    return 0;
}