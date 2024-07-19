#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    n++;
    vector<long long> prices(n);
    for (int i = 1;i < n;i++) {
        cin >> prices[i];
    }
    vector<long long> f(n);
    auto g = f;
    if (n)f[1] = prices[1];
    for (int i = 2;i < n;i++) {
        f[i] = min(f[i - 1], prices[i]);
        g[i] = max(g[i - 1], prices[i] - f[i - 1]);
    }
    cout << g[n - 1];
    return 0;
}
