#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
    long long a = 0, b = 0;
    cin >> a >> b;
    if (b > a)swap(a, b);
    long long x = a, y = b;
    while (b) {
        long long r = a % b;
        a = b;
        b = r;
    }
    cout << x * y / a;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")