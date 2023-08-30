#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
inline int fun1()
{
	static int x = 0;
	return x;
}

void fun(int)
{
	cout << "f(int)" << endl;
}
void fun(int*)
{
	cout << "f(int*)" << endl;
}
int main()
{

	fun(0);
	fun(NULL);
	fun((int*)NULL);


























	//int& ret = fun1();//权限的放大
	//const int& ret = fun1();//权限的平移
	//int ret = fun1();//拷贝

	//int Arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	////之前的我们
	//int size = sizeof(Arr) / sizeof(Arr[0]);
	//int i = 0;
	//for (i = 0;i < size;i++)
	//{
	//	cout << Arr[i] << ' ';
	//}
	//cout << endl;
	////现在的我们
	//for (auto e : Arr)
	//{
	//	cout << e << ' ';
	//}






















	////引用过程中,权限放大
	//const int a = 0;
	//int& b = a;

	////引用的过程中，变量d对变量c进行拷贝
	//const int& c = 0;
	//int d = c; 
	//
	//
	//int x = 0;
	//int& y = x;//变量x本身是可以被修改，变量y对变量x引用，也可以对变量x进行修改。这属于权限的平移
	//const int& z = x;//变量x本身是可以被修改，而变量z对变量x引用，不能对变量x进行修改。这属于权限的缩小

	//double e = 1.1;
	////int& i = e;
	//const int& i = e;
	//std::cout << i << std::endl;

	return 0;
}