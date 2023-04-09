#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

//前序遍历数组构建二叉树
BTNode* BinaryTreeCreate(BTDataType* str, int* pi);

//二叉树的销毁
void BinaryTreeDestroy(BTNode* root);

//二叉树的节点个数
int BinaryTreeSize(BTNode* root);

//二叉树叶节点的个数
int BinaryTreeLeafSize(BTNode* root);

//二叉树第k层的节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);

//二叉树查找值为xd的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root);

//二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);

//二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);

//二叉树层序遍历
void BinaryTreeLevelOrder(BTNode* root);

//判断是不是完全二叉树
bool BinaryTreeComplete(BTNode* root);