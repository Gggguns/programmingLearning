#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Date
{
public:
	Date()
	{}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
template<class T,class Container >
class Stack
{
	void push(const T& val)
	{
		C.push_back(val);
	}
	void pop(const T& val)
	{
		C.pop_back(val);
	}
	~Stack()
	{

	}
private:
	Container C;
};

int main()
{	
	/*Date d1;
	Date d2(2023, 2, 2);*/
	
	return 0;
}