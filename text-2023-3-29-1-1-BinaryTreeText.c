#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-29-1-1-Queue.h"
int main()
{
	char arr[] = "ABC##DE###FG#H##I##";
	int len = strlen(arr);
	int i=0;
	BTNode*root=BinaryTreeCreate(arr,&i);

	//测试树节点
	int size=BinaryTreeSize(root);
	printf("TreeSize=%d\n", size);

	//k层节点的测试
	int sizek = BinaryTreeLevelKSize(root, 6);
	printf("TreeLevelkSize=%d\n", sizek);

	//叶节点的测试
	int LeafSize = BinaryTreeLeafSize(root);
	printf("LeafSize=%d\n", LeafSize);

	//前序测试
	BinaryTreePrevOrder(root);
	printf("\n");

	//中序测试
	BinaryTreeInOrder(root);
	printf("\n");

	//后序测试
	BinaryTreePostOrder(root);
	printf("\n");

	//层序测试
	BinaryTreeLevelOrder(root);
	printf("\n");

	BinaryTreeDestroy(root);
	return 0;
}