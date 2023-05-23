#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
template <typename T>
void Swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}
int main()
{
	int a = 0, b;
	double c = 0, d = 0;
	cout << "请输入交换的两个整形数据：" << endl;
	cin >> a >> b;
	Swap(a, b);
	cout << "a=" << a << ' ' << "b=" << b << endl;
	cout << "请输入交换的两个浮点型数据：" << endl;
	cin >> c >> d;
	Swap(c, d);
	cout << "c=" << c << ' ' << "d=" << d << endl;
	return 0;
}