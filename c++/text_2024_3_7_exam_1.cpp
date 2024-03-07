#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    list<long> L(n);
    for (auto& e : L)
        cin >> e;
    int Left = 0, Right = 0;
    cin >> Left >> Right;
    Right = n - Right;
    auto LeftIt = L.begin();
    auto RightIt = L.end();
    while (--Left)
    {
        LeftIt++;
    }
    while (Right--)
    {
        RightIt--;
    }
    reverse(LeftIt, RightIt);
    for (auto e : L)
        cout << e << ' ';
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")