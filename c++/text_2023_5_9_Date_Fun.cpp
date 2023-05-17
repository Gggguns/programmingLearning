#define _CRT_SECURE_NO_WARNINGS
#include"text_2023_5_9_Data.h"


//初始化析构函数
Data::Data(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;
}

//拷贝构造函数
Data::Data(const Data& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//运算符重载 
//大于
bool Data::operator<(const Data& d)
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

//等于
bool Data::operator==(const Data& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	else
		return false;
}
