#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-29-1-1-Queue.h"

//前序遍历数组构建二叉树
BTNode* BinaryTreeCreate(BTDataType* str, int* pi)
{
	if (str[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if(root)
		root->val = str[(*pi)++];
	else
	{
		perror("malloc fail");
		return NULL;
	}
	root->left = BinaryTreeCreate(str, pi);
	root->right = BinaryTreeCreate(str, pi);
	return root;
}

//二叉树的销毁
void BinaryTreeDestroy(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestroy(root->left);
	BinaryTreeDestroy(root->right);
	free(root);
}

//二叉树的节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + 1 + BinaryTreeSize(root->right);
}

//二叉树叶节点的个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	int left = BinaryTreeLeafSize(root->left);
	int right = BinaryTreeLeafSize(root->right);
	if (right + left == 0)
		return 1;
	return right + left;
}

//二叉树第k层的节点个数
int BinaryTreeLevelKSize(BTNode* root,int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
	}

//二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
		return root;
	BTNode* pleft = BinaryTreeFind(root->left, x);
	if (pleft)
		return pleft;
	BTNode* pright = BinaryTreeFind(root->right, x);
	if (pright)
		return pright;
	return NULL;
}

//二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->val);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

//二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->val);
	BinaryTreeInOrder(root->right);
}

//二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->val);
}

//二叉树层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->val);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);	
	}
	QueueDestroy(&q);
}

//判断是不是完全二叉树
bool BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			break;
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}