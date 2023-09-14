#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Stack
{
public:
	Stack()
	{
		cout << "栈的初始化" << endl;
		_arr = (int*)malloc(sizeof(int) * 4);
		_size = 0;
		_capacity = 4;
		_top = 0;
	}

	Stack(const Stack& s)
	{

	}

	~Stack()
	{
		cout << "栈的销毁" << endl;
		free(_arr);
		_size = 0;
		_capacity = 0;
	}
private:
	int* _arr;
	int _size;
	int _capacity;
	int _top;
};
class Queue
{
public:
private:
	Stack s;
};
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	//Date(const Date d)
	/*Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}*/
private:
	int _year=1;
	int _month=1;
	int _day=1;
};
int main()
{
	/*Date d1(2023, 9, 14);
	Date d2(d1);*/

	Stack s1;
	Stack s2(s1);


	/*Queue q;
	Stack s2;*/
	return 0;
}