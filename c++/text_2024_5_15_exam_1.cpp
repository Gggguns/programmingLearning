#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    long long n = 0, m = 0;
    long long mod = 109;
    cin >> n >> m;
    size_t Sum = n;
    for (int i = 1;i < m;i++) {
        Sum *= (n - 1);
        Sum %= mod;
    }
    cout << Sum;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")