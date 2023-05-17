#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_5_9_Date.h"

// 获取某年某月的天数

int GetMonthDay(int year, int month);



// 全缺省的构造函数

Date::Date(int year = 1900, int month = 1, int day = 1)
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
	return;
}



// 析构函数

~Date();



// 日期+=天数

Date& operator+=(int day);



// 日期+天数

Date operator+(int day);



// 日期-天数

Date operator-(int day);



// 日期-=天数

Date& operator-=(int day);



// 前置++

Date& operator++();



// 后置++

Date operator++(int);



// 后置--

Date operator--(int);



// 前置--

Date& operator--();



// >运算符重载

bool operator>(const Date& d);



// ==运算符重载

bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	else
		return false;
}



// >=运算符重载

bool operator >= (const Date& d);



// <运算符重载

bool Date::operator < (const Date& d)
{
	if (_year >= d._year)
		return false;
	else if (_year == d._year && _month >= d._month)
		return false;
	else if (_year == d._year && _month == d._month && _day >= d._day)
		return false;
	else
		return true;
}



// <=运算符重载

bool operator <= (const Date& d);



// !=运算符重载

bool operator != (const Date& d);



// 日期-日期 返回天数

int operator-(const Date& d);