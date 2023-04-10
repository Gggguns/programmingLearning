#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
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

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;
    if (subRoot == NULL)
        return true;
    if (isSameTree(root, subRoot))
        return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    return 0;
}