#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
//计算树的节点个数
int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    else
        return TreeSize(root->left) + 1 + TreeSize(root->right);
}
//前序遍历
void BinaryTreePrevOrder(struct TreeNode* root, int* arr, int* pi)
{
    if (root == NULL)
        return;
    arr[(*pi)++] = root->val;
    BinaryTreePrevOrder(root->left, arr, pi);
    BinaryTreePrevOrder(root->right, arr, pi);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = TreeSize(root);
    int* arr = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    if (arr)
        BinaryTreePrevOrder(root, arr, &i);
    else
    {
        perror("malloc fail");
    }
    return arr;
}
int main()
{
    return 0;
}