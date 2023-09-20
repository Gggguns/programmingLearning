#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int main()
{
	int* ptr = new int(10);

	int* p = new int[10] {1,2,3,4,5,6,7,8,9,10};
	int i = 0;
	for (i = 0;i < 10;i++)
	{
		cout << p[i] << endl;
	}
	
	//在空间上执行析构函数，完成对象中资源的清理
	delete ptr;
	//调用N次析构函数，析构N个对象的资源
	delete[] p;
	return  0;
}