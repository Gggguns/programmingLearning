#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct ListNode
{
	ListNode(int val)
		:_val(val)
	{
		cout << "初始化" << endl;
	}
	int _val;
};
void testlist1()
{
	//开空间+调用构造函数初始化
	ListNode* head = new ListNode(1);
}
void testlist2()
{
	//注意：head现在指向的只不过是一段具有和ListNode对象同样大小的空间，还算不上对象。因为构造函数还没执行
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	new(head)ListNode(8);//注意：如果ListNode有无参数的构造函数，这里可以不给初始值8。

}
int main()
{
	testlist2();
	/*int* ptr = new int(10);

	int* p = new int[10] {1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		cout << p[i] << endl;
	}
	
	
	delete ptr;
	delete[] p;*/
	return  0;
}