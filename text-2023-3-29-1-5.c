#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef struct BinaryTreeNode
{
    char val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}BTNode;

BTNode* PrevOrderCreateTree(char* arr, int* pi)
{
    if (arr[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    if (!root)
    {
        perror("malloc fail");
        return NULL;
    }
    root->val = arr[(*pi)++];
    root->left = PrevOrderCreateTree(arr, pi);
    root->right = PrevOrderCreateTree(arr, pi);
    return root;
}

void BinaryTreeInOrder(BTNode* root)
{
    if (root == NULL)
        return;
    BinaryTreeInOrder(root->left);
    printf("%c ", root->val);
    BinaryTreeInOrder(root->right);
}

int main() {
    char arr[101];
    scanf("%s", arr);
    int i = 0;
    BTNode* root = PrevOrderCreateTree(arr, &i);
    BinaryTreeInOrder(root);
    return 0;
}