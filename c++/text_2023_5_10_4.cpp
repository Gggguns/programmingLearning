#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>
using namespace std;

int getmothday(int year, int month)
{
    while (month > 12)
    {
        month = month - 12;
        year++;
    }
    while (month < 12)
    {
        month = month + 12;
        year--;
    }
    static int arr[13] = { 0,31,28,31,30,31,30 ,31,31 ,30,31,30,31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        return arr[month] + 1;
    else
    {
        return arr[month];
    }
}
class Date
{
public:
    friend ostream& operator<<(ostream& out, const Date& d);
    friend istream& operator>>(istream& in, Date& d);
    Date operator+(int day)
    {
        Date ret(*this);
        ret._day = ret._day + day;
        while (ret._day > getmothday(ret._year, ret._month))
        {
            ret._day = ret._day - getmothday(ret._year, ret._month);
            ret._month++;
            while (ret._month > 12)
            {
                ret._month=ret._month - 12;
                ret._year++;
            }
        }
        return ret;

    }
    Date(int year = 0, int month = 0, int day = 0)
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
private:
    int _year;
    int _month;
    int _day;
};

istream& operator>>(istream& in, Date& d)
{
    cin >> d._year >> d._month >> d._day;
    return in;
}

ostream& operator<<(ostream& out, const Date& d)
{
    out << d._year << '-' << setw(2) << setfill('0') << d._month << '-' << d._day << endl;
    return out;
}



int main() {
    int b=0;
    Date a;
    int n;
    cin >> n;
    while (n--)
    { // 注意 while 处理多个 case
        cin >> a;
        cout << (a + b) << endl;
    }
}