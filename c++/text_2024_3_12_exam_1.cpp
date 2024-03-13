#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <iostream>
#include<cmath>
using namespace std;
int GetMonthDay(int year, int month)
{
    static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)))
        return arr[month] + 1;
    return arr[month];
}
struct Date
{
    Date operator++()
    {
        _day++;
        if (GetMonthDay(_year, _month) < _day)
        {
            _day -= GetMonthDay(_year, _month);
            _month++;
            while (_month > 12)
            {
                _month -= 12;
                _year++;
            }
        }
        return *this;
    }
    bool operator<(Date& d)
    {
        if (_year < d._year)return true;
        if (_year == d._year && _month < d._month)return true;
        if (_year == d._year && _month == d._month && _day < d._day)return true;
        return false;
    }
    int _year;
    int _month;
    int _day;
};
istream& operator>>(istream& in, Date& d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
bool IsChrime(int num)
{
    if (num < 2)return false;
    if (num == 2)return true;
    for (int i = 2;i <= sqrt(num);i++)
    {
        if (num % i == 0)return false;
    }
    return true;
}
int main() {
    Date d1, d2;
    while (cin >> d1 >> d2)
    {
        long long Sum = 0;
        ++d2;
        while (d1 < d2)
        {
            if (IsChrime(d1._month))
            {
                Sum += 1;
            }
            else
            {
                Sum += 2;
            }
            ++d1;
        }
        cout << Sum << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")