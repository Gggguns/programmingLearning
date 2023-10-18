#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int GetMonthDay(int year, int month)
{
    static int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
    {
        return arr[month] + 1;
    }
    return arr[month];
}
int main()
{
    int year = 0, month = 0, day = 0;
    cin >> year >> month >> day;
    int i = 0;
    int sum = 0;
    for (i = 1, sum = 0;i < month;i++)
    {
        sum += GetMonthDay(year, i);
    }
    sum += day;
    cout << sum;
    return 0;
}