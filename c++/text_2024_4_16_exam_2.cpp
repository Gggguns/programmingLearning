#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> cost(n), dp(n + 1);
    for (auto& e : cost)cin >> e;
    for (int i = 2;i <= n;i++) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    cout << dp[n];
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")