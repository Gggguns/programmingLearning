#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    n++;
    vector<long long> prices(n);
    auto f = prices;auto g = prices;
    for (long long i = 1;i < n;i++)cin >> prices[i];
    if (n) {
        f[1] = -prices[1];
    }
    for (long long i = 2;i < n;i++) {
        f[i] = max(f[i - 1], g[i - 1] - prices[i]);
        g[i] = max(f[i - 1] + prices[i], g[i - 1]);
    }
    cout << max(f[n - 1], g[n - 1]);
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")