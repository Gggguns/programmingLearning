#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;
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
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 0, int month = 0, int day = 0)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	Date operator+(int day)
	{
		Date d(*this);
		if (day < 0)
		{
			day = -day;
			return d - day;
		}
		d._day += day;
		while (d._day > getmonthday(d._year, _month))
		{
			d._day -= getmonthday(d._year, d._month);
			d._month++;
			while (d._month > 12)
			{
				d._month -= 12;
				d._year++;
			}
		}
		return d;
	}
	Date operator-(int day)
	{
		Date d(*this);
		if (day < 0)
		{
			day = -day;
			return d + day;
		}
		d._day -= day;
		while (d._day < 0)
		{
			d._month--;
			d._day += getmonthday(d._year, d._month);
			while (d._month < 0)
			{
				d._month += 12;
				d._year--;
			}
		}
		return d;
	}

private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << '-' << setw(2) << setfill('0') << d._month << '-' << setw(2) << setfill('0') << d._day << endl;
	return out;
}
istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
int main()
{
	int year = 0, day = 0;
	cin >> year >> day;
	Date d(year, 1, 0);
	cout << (d + day) << endl;
	return 0;
}