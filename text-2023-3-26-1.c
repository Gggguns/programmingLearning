#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int TreeDataType;
struct TreeNode
{
    TreeDataType val;
    struct TreeNode* left;
    struct TreeNode* right;
};
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;
    if (root->left && root->left->val != root->val)
        return false;
    if (root->right && root->right->val != root->val)
        return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}
int main()
{
    return 0;
}