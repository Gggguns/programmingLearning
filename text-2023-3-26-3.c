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

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return root;
    struct TreeNode* p = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(p);
    return root;
}

int main()
{
	return 0;
}