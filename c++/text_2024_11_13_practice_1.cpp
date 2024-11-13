#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int n = 0, sum = 0;
    cin >> n;
    while (n >= 15)
    {
        sum += 2;
        n -= 15;
    }
    cout << sum;
    return 0;
}