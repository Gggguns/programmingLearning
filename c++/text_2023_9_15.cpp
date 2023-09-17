#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdbool.h>
using namespace std;
int GetMonthDay(int year, int month)
{
	static int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return arr[month] + 1;
	else
		return arr[month];
}
class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);
public:
	//日期类的初始化
	Date(int year = 0, int month = 0, int day = 0)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//日期类的拷贝
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//加号运算符的重载
	Date operator+(const int& day)
	{
		//判断是否为负数
		if (day < 0)
		{
			return *this - (-day);
		}
		//原数据不能动，我们需要拷贝一份进行操作
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day = ret._day - GetMonthDay(ret._year, ret._month);
			ret._month++;
			while (ret._month > 12)
			{
				ret._month = ret._month - 12;
				ret._year++;
			}
		}
		return ret;
	}
	//减号
	Date operator-(const int& day)
	{
		//判断是否为负数
		if (day < 0)
		{
			return *this + (-day);
		}
		//同样的原数据不能动，拷贝一份进行操作
		Date ret(*this);
		ret._day = ret._day - day;
		while (ret._day < 0)
		{
			ret._month--;
			while (ret._month < 1)
			{
				ret._month = ret._month + 12;
				ret._year--;
			}
			ret._day = ret._day + GetMonthDay(ret._year, ret._month );
		}
		return ret;
	}
	//前置++
	Date& operator++()
	{
		*this = *this + 1;
		return *this;
	}
	//后置++
	Date operator++(int)
	{
		Date ret(*this);
		*this = *this + 1;
		return ret;
	}
	//前置--
	Date& operator--()
	{
		*this = *this - 1;
		return *this;
	}
	//后置--
	Date operator--(int)
	{
		Date ret = *this;
		*this = *this - 1;
		return ret;
	}
	//比较运算符的重载
	//大于>
	bool operator>(const Date& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day > d._day)
			return true;
		else
			return false;
	}
	//等于==
	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}
	//对于后面的运算符，我们直接复用前面的函数就行了
	//小于<
	bool operator<(const Date& d)
	{
		return !(*this > d || *this == d);
	}
	//小于等于<=
	bool operator<=(const Date& d)
	{
		return !(*this > d);
	}
	//大于等于>=
	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}
	//不等于！=
	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}
	//日期相减
	int operator-(const Date& d)
	{
		int flat = 1;
		Date MaxDate(*this);
		Date MinDate(d);
		if (MaxDate < MinDate)
		{
			flat = flat * -1;
			MaxDate = d;
			MinDate = *this;
		}
		int i = 0;
		while (MaxDate != MinDate)
		{
			++MinDate;
			++i;
		}
		return i * flat;
	}
private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << '.' << d._month << '.' << d._day << endl;
	return out;
}
void testDate1()
{
	Date d1(2023, 9, 15);
	Date d2(2023, 9, 15);
	//d1 = d1 + (-10187);
	cout << d1++ ;
	cout << "d1:" << d1 ;
	cout << ++d2 ;
	cout << "d2:" << d2;
}
void testDate2()
{
	int i = 10;
	int j = 10;
	/*cout << i - 10<<endl;
	cout << i << endl;*/
	cout << i++ << endl;
	cout << "i:" << i << endl;
	cout << ++j << endl;
	cout << "j:" << j << endl;
}
void testDate3()
{
	Date  i(2023, 9, 16);
	Date j(2023, 9, 16);
	cout << "操作前i的值为：" << i;
	cout << "前置--i的返回值为：" << --i;
	cout << "前置--后i的值为：" << i;

	cout << "操作前j的值为：" << j;
	cout << "后置--j的返回值为：" << j--;
	cout << "后置--后j的值为：" << j;
}
void testDate4()
{
	Date d1(2023, 9, 13);
	Date d2(2023, 9, 17);
	Date d3(2022, 9, 9);
	Date d4(2022, 10, 9);

	cout << "d1:"<<d1<<"d2:"<<d2;
	cout << (d1 > d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 < d2) << endl;

	cout << "d2:" << d2 << "d3:" << d3;
	cout << (d2 > d3) << endl;
	cout << (d2 == d3) << endl;
	cout << (d2 < d3) << endl;

	cout << "d3:" << d3 << "d4:" << d4;
	cout << (d3 > d4) << endl;
	cout << (d3 == d4) << endl;
	cout << (d3 < d4) << endl;
}
void testDate5()
{
	Date d1(2004, 4, 6);
	Date d2(2043, 10, 8);
	cout << d1 - d2 << endl;
	cout << d2 - d1 << endl;
}
int main()
{

	testDate5();
	////定义变量i赋值10
	//int i = 10;
	////定义变量j,对变量i的数据进行备份
	//int j = i;
	//int a = 0;
	//int b = 0;
	//a = b = j;
	//cout << "a:" << a << endl << "b:" << b << endl;
	return 0;
}