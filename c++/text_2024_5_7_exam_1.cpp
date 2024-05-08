#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    long long a = 0, b = 0, h = 0, k = 0;
    cin >> a >> h >> b >> k;
    long long Sum = 0;

    while (h > 0 && k > 0) {
        Sum = Sum + (a + b);
        h = h - b;
        k = k - a;
    }
    if (h > 0)Sum += (a * 10);
    if (k > 0)Sum += (b * 10);
    cout << Sum;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")