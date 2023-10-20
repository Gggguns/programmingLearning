#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
bool PerfectNum(int num)
{
    int Sum = 0;
    int i = 0;
    for (i = 1;i < num;i++)
    {
        if (num % i == 0)
        {
            Sum += i;
        }
    }
    return Sum == num;
}
int main()
{
    int num = 0;
    cin >> num;
    int i = 0;
    int count = 0;
    for (i = 2;i < num;i++)
    {
        if (PerfectNum(i))
        {
            count++;
        }
    }
    cout << count;

    return 0;
}