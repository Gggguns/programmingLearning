#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Data
{
public:
	/*Data(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}*/


	int _year;
	int _month;
	int _day;
};

bool operator>(Data& x1, Data& x2)
{
	if (x1._year < x2._year)
		return false;
	if (x1._year == x2._year && x1._month < x2._month)
		return false;
	if (x1._year == x2._year && x1._month == x2._month && x1._day < x2._day)
		return false;
	return true;
}

bool operator<(Data& x1, Data& x2)
{
	if (x1._year > x2._year)
		return false;
	if (x1._year == x2._year && x1._month > x2._month)
		return false;
	if (x1._year == x2._year && x1._month == x2._month && x1._day > x2._day)
		return false;
	return true;
}

int main()
{
	Data dd;
	Data cc;
	/*Data d1(2023, 5, 10);
	Data d2(2023, 4, 20);*/
	/*cout << (d1 < d2) << endl;
	cout << (d1 > d2) << endl;*/
	return 0;
}
