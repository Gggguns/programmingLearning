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
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return isSameTree(root->left, root->right);
}

int main()
{
	return 0;
}