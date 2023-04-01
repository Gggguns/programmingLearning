#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int rleft = maxDepth(root->left);
    int rright = maxDepth(root->right);
    return rleft > rright ? rleft + 1 : rright + 1;
}

int main()
{
    return 0;
}