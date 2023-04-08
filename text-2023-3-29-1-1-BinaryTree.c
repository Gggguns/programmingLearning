#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-29-1-1-BinaryTree.h"

//前序遍历数组构建二叉树
BTNode* BinaryTreeCreate(BTDataType* str, int size, int* pi)
{
	BTNode root;
	int i = 0;
	BinaryTreePrevOrder(&root,str,&i);

}

//二叉树的销毁
void BinaryTreeDestory(BTNode* root);

//二叉树的节点个数
int BinaryTreeSize(BTNode* root);

//二叉树叶节点的个数
int BinaryTreeLeafSize(BTNode* root);

//二叉树第k层的节点个数
int BinaryTreeLevelKSize(BTNode* root，(int k));

//二叉树查找值为xd的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root,BTDataType*str,int*pi)
{
	if (str[*pi] == '#')
		root = NULL;
	root->val = str[*pi++];
	BinaryTreePrevOrder(root->left,str,pi);
	BinaryTreePrevOrder(root->right,str,pi);
}

//二叉树中序遍历
void BinaryTreeInOrder(BTNode* root, BTDataType* str, int* pi)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left,str,pi);
	printf("%c ", root->val);
	BinaryTreeInOrder(root->right,str,pi);
}

//二叉树后序遍历
void BinaryTreePostOrder(BTNode* root, BTDataType* str, int* pi)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->left,str,pi);
	BinaryTreePostOrder(root->right,str,pi);
	printf("%c ", root->val);
}

//二叉树层序遍历
void BinaryTreeLevelOrder(BTNode* root);

//判断是不是完全二叉树
bool BinaryTreeComplete(BTNode* root);