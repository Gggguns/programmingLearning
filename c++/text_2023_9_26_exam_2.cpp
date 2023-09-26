#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
void change(long long num, int& N, string& str)
{
    while (num)
    {
        int remain = num % N;
        if (remain <= 9)
        {
            str += remain + '0';
        }
        else
        {
            str += remain + 'A' - 10;
        }
        num /= N;
    }
}
int main()
{
    long long num = 0;
    int N = 0;
    int flat = 1;
    cin >> num >> N;
    string str;
    if (num == 0)
    {
        str += '0';
    }
    else
    {
        if (num < 0)
        {
            num = -num;
            flat = -1;
        }
        change(num, N, str);
        if (flat == -1)
        {
            str += '-';
        }
        reverse(str.begin(), str.end());
    }
    cout << str;
    return 0;
}