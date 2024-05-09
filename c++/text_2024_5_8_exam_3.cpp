#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    str = ' ' + str;
    int n = str.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(n));
    for (int i = n - 1;i >= 1;i--) {
        for (int j = i;j < n;j++) {
            if (str[i] == str[j]) {
                if (j - i < 2)dp[i][j] = j - i + 1;
                else dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j - 1]));
        }
    }
    cout << dp[1][n - 1];
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")