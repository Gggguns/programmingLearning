#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int getmonthday(int year, int month)
{
	static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (month > 12)
	{
		month -= 12;
		year++;
	}
	while (month < 0)
	{
		month += 12;
		year--;
	}
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return arr[month] + 1;
	else
		return arr[month];
}
class Date
{
public:
	Date(int year = 0, int month = 0, int day = 0)
		:_year(year)
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

	//比较大小运算符重载
	//等于
	bool operator==(Date& d)
	{
		if (_year == d._year && _month == d._month && _day == d._day)
			return true;
		else
			return false;
	}
	//大于
	bool operator>(Date& d)
	{
		if (*this == d)
			return false;
		else if (_year < d._year)
			return false;
		else if (_year == d._year && _month < d._month)
			return false;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return false;
		else
			return true;
	}
	//大于等于
	bool operator>=(Date& d)
	{
		if ((*this == d) || (*this > d))
			return true;
		else
			return false;
	}
	//小于
	bool operator<(Date& d)
	{
		if (*this >= d)
			return false;
		else
			return true;
	}
	//小于等于
	bool operator<=(Date& d)
	{
		if (*this > d)
			return false;
		else
		{
			return true;
		}
	}


	//运算符重载
	// 相加
	Date operator+(int day)
	{
		Date d(*this);
		if (day < 0)
		{
			day = -day;
			d = d - day;
			return d;
		}
		d._day += day;
		//cout << d._year<<' '<<d._month<<' '<<d._day << endl;
		while (d._day > getmonthday(d._year, d._month))
		{
			d._day -= getmonthday(d._year, d._month);
			d._month += 1;
			while (d._month > 12)
			{
				d._year++;
				d._month -= 12;
			}
		}
		return d;
	}
	//相减
	// 
	Date operator-(int day)
	{
		Date d(*this);
		if (day < 0)
		{
			day = -day;
			d = d + day;
			return d;
		}
		d._day -= day;
		while (d._day < 0)
		{
			d._month--;
			d._day += getmonthday(d._year, d._month);
			while (d._month < 1)
			{
				d._month += 12;
				d._year--;
			}
		}
		return d;
	}
	//
	int operator-(Date& d)
	{
		int i = 0;
		int sign = 1;
		Date Max(d);
		Date Min(*this);
		if (*this > d)
		{
			Max = *this;
			Min = d;
			sign = -sign;
		}
		while (Min < Max)
		{
			Min = Min + 1;
			i++;
		}
		int x;
		return i * sign;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	int num1 = 0, num2 = 0;
	cin >> num1 >> num2;
	Date d1(num1 / 10000, ((num1 / 100) % 100), num1 % 100);
	Date d2(num2 / 10000, ((num2 / 100) % 100), num2 % 100);
	cout << d1 - d2+1 << endl;
	return 0;
}