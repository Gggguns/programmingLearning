#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//首先，我们先定义一个参数列表，我们通常交换两个类型相同的函数，所以，这里我们只需要一个模板参数
template<class T>
//其次，完成交换函数的实现
void Swap(T& left,T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}
//两数相加
template<class T2>
T2 Add(const T2& x, const T2& y)
{
	cout << "我走了函数模板\n";
	return x + y;
}

//专门处理int类型
int Add(int left,int right)
{
	cout << "我没走函数模板\n";
	return left+right;
}
void testSwap1()
{
	double a = 10.2;
	double b = 12.3;
	cout << "交换前：" << endl;
	cout << "a:" << a << ' ' << "b:" << b << endl;
	Swap(a, b);
	cout << "交换后:\n";
	cout << "a:" << a << ' ' << "b:" << b << endl;
}

void testSwap2()
{
	double a = 10.5;
	int b = 90;
	int c = 10;
	//Swap(a, b);
	//隐式类型转换，编译器会传过去的类型自动推导
	cout << Add(b, c) << endl;
	cout << Add(a, (double)b) << endl;//对变量b进行类型转换

	//显示类型转化
	//cout << Add(a, b) << endl;
	cout << Add<double>(a, b) << endl;
	
}

void testSwap3()
{
	int a = 10;
	int b = 20;
	cout << Add(a, b) << endl;
}
int main()
{
	testSwap3();

	return 0;
}