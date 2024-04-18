#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
    long long n = 0;
    long long a = 0, b = 1, c = 1;
    cin >> n;
    while (c < n) {
        a = b;
        b = c;
        c = a + b;
    }
    long long res = (c - n) > (n - b) ? (n - b) : (c - n);
    cout << res;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")