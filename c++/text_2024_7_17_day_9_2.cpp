#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    vector<long long> dp(n);
    long long a = 0, b = 1, c = 2;
    if (n <= 2)cout << n;
    else {
        long long i = 3;
        while (i <= n) {
            a = b;
            b = c;
            c = a + b;
            i++;
        }
        cout << c;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")