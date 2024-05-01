#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    n *= 3;
    vector<long long> v(n);
    for (long long i = 0;i < n;i++)cin >> v[i];
    sort(v.begin(), v.end());
    long long Sum = 0;
    for (long long i = n / 3;i < n;i += 2)Sum += v[i];
    cout << Sum;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")