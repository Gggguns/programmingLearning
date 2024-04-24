#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = dp[1] = 1;
    dp[2] = 2;
    for (int i = 2;i <= n;i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n];
    return 0;
}
