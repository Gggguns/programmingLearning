#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            if (s1[i] == s2[j])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")