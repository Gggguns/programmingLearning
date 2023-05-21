#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_5_9_Date.h"
using namespace std;

// 获取某年某月的天数

int Date::GetMonthDay(int year, int month)const
{
	while (12 < month)
	{
		month--;
		year++;
	}
	while (month < 0)
	{
		month += 12;
		year--;
	}
	static int arr[13] = { 0,31,28,31,30,31,30,31 ,31,30 ,31,30 ,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return arr[month] + 1;
	else
		return arr[month];
}



// 全缺省的构造函数

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

}



// 拷贝构造函数

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}



// 赋值运算符重载

// d2 = d3 -> d2.operator=(&d2, d3)

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}



// 析构函数
Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}



// 日期+=天数

Date& Date::operator+=(int day)
{
	_day = _day + day;
	while (GetMonthDay(_year, _month) < _day)
	{
		_day = _day - GetMonthDay(_year, _month);
		_month++;
		while (_month > 12)
		{
			_month = _month - 12;
			_year++;
		}
	}
	return *this;
}



// 日期+天数

Date Date::operator+(int day)const
{
	Date d(*this);
	d += day;
	return d;

}



// 日期-天数

Date Date::operator-(int day)const
{
	Date d(*this);
	if (day < 0)
	{
		day = -day;
		return d + day;
	}
	else
	{
		d._day = d._day - day;
		while (0 > d._day)
		{
			d._day = d._day + GetMonthDay(d._year, d._month);
			d._month--;
			while (d._month <= 0)
			{
				d._month = d._month + 12;
				d._year--;
			}
		}
		return d;
	}
}



// 日期-=天数

Date& Date::operator-=(int day)
{
	*this = *this - day;
	return *this;
}



// 前置++

Date& Date::operator++()
{
	*this += 1;
	return *this;
}



// 后置++

Date Date::operator++(int)
{
	Date d(*this);
	*this += 1;
	return d;
}



// 后置--

Date Date::operator--(int)
{
	Date d(*this);
	*this -= 1;
	return d;
}



// 前置--

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}



// >运算符重载

bool Date::operator>(const Date& d)const
{
	if (*this <= d)
		return false;
	else
		return true;
}



// ==运算符重载

bool Date::operator==(const Date& d)const
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	else
		return false;
}



// >=运算符重载

bool Date::operator >= (const Date& d)const
{
	if (*this < d)
		return false;
	else
		return true;
}



// <运算符重载

bool Date::operator < (const Date& d)const
{
	if (_year > d._year)
		return false;
	else if (_year == d._year && _month > d._month)
		return false;
	else if (_year == d._year && _month == d._month && _day >= d._day)
		return false;
	else
		return true;
}



// <=运算符重载

bool Date::operator <= (const Date& d)const
{
	if (*this < d || *this == d)
		return true;
	else
		return false;
}



// !=运算符重载

bool Date::operator != (const Date& d)const
{
	if (*this == d)
		return false;
	else
		return true;
}



// 日期-日期 返回天数

int Date::operator-(const Date& d)const
{
	Date Max(*this);
	Date Min(d);
	if ((*this) < d)
	{
		Max = d;
		Min = *this;
	}
	int i = 0;
	while (Min < Max)
	{
		i++;
		++Min;
	}
	if (*this > d)
		return i;
	else
		return -i;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	int year, month, day;
	in >> year >> month >> day;
	if (month > 12 || day > d.GetMonthDay(year, month))
	{
		cout << "非法日期" << endl;
	}
	else
	{
		d._year = year;
		d._month = month;
		d._day = day;
	}
	return in;
}