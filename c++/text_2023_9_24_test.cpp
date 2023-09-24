#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//void Swap(int& left, int& right)
//{
//	int tmp = left;
//	left = right;
//	right = tmp;
//}
//void Swap(double& left, double& right)
//{
//	double tmp = left;
//	left = right;
//	right = tmp;
//}


//泛型编程
//函数模板
////模板参数名字如果想简洁一点，可以取名为T.
//template<class T>
////如果你想取个好听的名字也行
//template<class name1>
////如果你不喜欢class，可以用typename
//template<typename name2>
////如果你想定义多个，需要以逗号作为分割符
//template<class T1,class T2>

//交换函数可能交换两个不同类型的数据，需要用到两个模板参数
template<class T1,class T2>
//模板参数其实就相当于类型
void Swap(T1& left, T2& right)
{
	T1 tmp = left;
	left = right;
	right = tmp;
}


void testSwap1()
{
	int a = 98;
	char b = 'a';
	cout << "交换前：" << endl;
	cout << "a:" << a << ' ' << "b:" << b << ' ' << endl;
	//调用交换函数
	Swap(a, b);
	cout << "交换后：" << endl;
	cout << "a:" << a << ' ' << "b:" << b << ' ' << endl;
}

int main()
{ 
	testSwap1();




	return 0;
}



















//int main(int agc, char* agv[], char* env[])
//{
//	int i = 0;
//	for (i = 0;agv[i];i++)
//	{
//		cout << agv[i] << endl;
//	}
//	return 0;
//}