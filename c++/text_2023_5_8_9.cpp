#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
int getmonthday(int year, int month)
{
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
	static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return arr[month] + 1;
	else
		return arr[month];
}
class Date
{
public:
	Date(int year = 0, int month = 0, int day = 0)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	Date operator+(int day)
	{
		_day += day;
		while (_day > getmonthday(_year, _month))
		{
			_day -= getmonthday(_year, _month);
			_month++;
			while (_month > 12)
			{
				_month -= 12;
				_year++;
			}
		}
	}
	Date operator-(int day)
	{
		_day -= day;
		while (_day < 0)
		{
			_day += getmonthday(_year, _month-1);
			_month--;
			while (_month < 0)
			{
				_month += 12;
				_year--;
			}
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