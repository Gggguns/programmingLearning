#define _CRT_SECURE_NO_WARNINGS
#include"BinarySearchTree.h"
#define N 10
void testBST1()
{
	zjh::BinarySearchTree<int> T;
	srand(time(NULL));
	int arr[N] = {1,4,3,2,5,6,78,9,8,8};
	
	for (auto e : arr)
	{
		T.Insert(e);
	}
	
	for (auto e : arr)
	{
		cout << e << ' ';
	}
	cout << endl;
	cout<<T.Find(1);
	cout << endl;
	T.Inorder();
	cout << endl;
	for (auto e : arr)
	{
		T.erase(e);
		T.Inorder();
		cout << endl;
	}
	
}
int main()
{
	testBST1();
	return 0;
}