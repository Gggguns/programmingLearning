#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> f(n);
    auto g = f;
    auto prices = f;
    for (auto& e : prices)cin >> e;
    f[0] = prices[0];
    for (int i = 1;i < n;i++) {
        f[i] = min(f[i - 1], prices[i]);
        g[i] = max(g[i - 1], prices[i] - f[i - 1]);
    }
    if (n == 0)cout << 0;
    else if (g[n - 1] < 0)cout << 0;
    else cout << g[n - 1];
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")