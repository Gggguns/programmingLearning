#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n = 0, m = 0, x = 0, y = 0;
    cin >> n >> m >> x >> y;
    int dx[9] = { 1,1,-1,-1,-2,-2,2,2,0 };
    int dy[9] = { 2,-2,2,-2,-1,1,-1,1,0 };
    n += 1;
    m += 1;
    x += 1;
    y += 1;
    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));
    dp[0][1] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            for (int k = 0;k < 9;k++) {
                int a = x + dx[k];
                int b = y + dy[k];
                if (a > 0 && a <= n && b > 0 && b <= m && i == a && b == j) {
                    dp[i][j] = 0;
                    break;
                }
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")