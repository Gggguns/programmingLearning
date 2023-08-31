#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using  namespace std;

struct business
{
public:
	void Modify(string name)
	{
		name = name;
	}
private:
	string name;//姓名
	string _number;//电话
	string _address;//地址
};
class customer
{
public:
	void Modify(string name)
	{
		name = name;
	}
private:
	int name;//姓名
	int _number;//电话
	int _address;//地址
};



int main()
{
	//customer类实例化出的对象
	customer c1;
	customer c2;

	cout << sizeof(c1) << endl;
	cout << sizeof(c2) << endl;


	//c.Modify("M");
	return 0;
}