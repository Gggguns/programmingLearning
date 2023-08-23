#define _CRT_SECURE_NO_WARNINGS
#include"BinarySearchTree.h"
#define N 10
void testBST1()
{
	Key::BinarySearchTree<int> T;
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
void testBST2()
{
	Key::BinarySearchTree<int> T;
	int arr[] = { 10,2,30,4,15,46,18,10,1,12,17,12 };
	for (auto e : arr)
	{
		T.InsertR(e);
	}
	Key::BinarySearchTree<int> TT;
	TT = T;
	T.Inorder();
	cout << endl;
	TT.Inorder();
	cout << endl;
	/*cout<<T.FindR(80)<<endl;
	for (auto e : arr)
	{
		T.eraseR(e);
		T.Inorder();
		cout << endl;
	}*/
	
	
}
int main()
{
	testBST2();
	return 0;
}