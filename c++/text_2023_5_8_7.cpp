#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int getmonth(int year, int month)
{
	static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (month > 12)
	{
		month = month - 12;
		year++;
	}
	while (month < 0)
	{
		month = month + 12;
		year--;
	}
	if (month == 2 && ((year % 4 == 0 && year % 100 == 0) || year % 400 == 0))
	{
		return arr[month] + 1;
	}
	else
	{
		return arr[month];
	}
}
class Date
{
public:
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& out, Date& d);
	Date operator+(int day)
	{
		_day = _day + day;
		while (_day > getmonth(_year, _month))
		{

		}
	}
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
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
private:
	int _year;
	int _month;
	int _day;
};
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
ostream& operator<<(ostream& out, Date& d)
{
	out << d._year << '-' << d._month << '-' << d._day << endl;
	return out;
}

int main()
{
	return 0;
}