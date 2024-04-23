#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char ch;
            cin >> ch;
            if (ch == 'l')dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 4;
            else if (ch == 'o')dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 3;
            else if (ch == 'v')dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 2;
            else if (ch == 'e')dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][m];
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")