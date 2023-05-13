#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//日期
class Data
{
public:
	//初始化构造函数
	Data(int year = 0, int month = 0, int day = 0);

	//拷贝构造函数
	Data(const Data& d);

	//运算符重载
	//大于
	bool operator<(const Data& d);

	//等于
	bool operator==(const Data& d);

private:
	int _year;
	int _month;
	int _day;

};