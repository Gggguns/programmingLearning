#define _CRT_SECURE_NO_WARNINGS
#include"AVL.h"
void testAVL1()
{
	zjh::AVL<int, int> A;
	int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	for (auto e : arr)
	{
		A.Insert(make_pair(e,e));
	}

	int c;
}
int main()
{
	testAVL1();
	return 0;
}