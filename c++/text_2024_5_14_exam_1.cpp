#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n = 0;
    string str;
    cin >> str;
    str = ' ' + str;
    n = str.size();
    int Min = 0x3fffff;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = n - 1;i >= 1;i--) {
        for (int j = i;j < n;j++) {
            if (str[i] == str[j]) {
                if (j - i < 3)dp[i][j] = true;
                else dp[i][j] = dp[i + 1][j - 1];
            }
            if (dp[i][j]) {
                int lenth = j - i + 1;
                if (lenth > 1 && lenth < Min)Min = lenth;
            }
        }
    }
    if (Min == 0x3fffff)cout << -1;
    else cout << Min;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")