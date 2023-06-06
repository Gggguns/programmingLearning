#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year=0,int month=0,int day=0)
		:_year(year)
		,_month(month)
		,_day(day)
	{}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}
	int operator-(Date& dd)
	{
		int i = 0;
		Date d(*this);
		while (d < dd)
		{

		}
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	return 0;
}