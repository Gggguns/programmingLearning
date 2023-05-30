#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Date
{
public:
	friend istream& operator>>(istream& in, Date& d);
	friend ostream& operator<<(ostream& out, Date& d);
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