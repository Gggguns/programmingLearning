#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size() + 1, m = p.size() + 1;
        s = ' ' + s;
        p = ' ' + p;
        vector<vector<bool>> dp(n, vector<bool>(m));
        dp[0][0] = true;
        for (int i = 2;i < m;i += 2)
            if (p[i] == '*')dp[0][i] = true;
            else break;
        for (int i = 1;i < n;i++) {
            for (int j = 1;j < m;j++)
            {
                if (p[j] == s[i] || p[j] == '.')dp[i][j] = dp[i - 1][j - 1];
                else if (p[j] == '*') {
                    dp[i][j] = dp[i][j - 2] || (p[j - 1] == '.' || p[j - 1] == s[i]) && dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
int main()
{
    Solution s;
    s.isMatch("aaa","ac*");
	return 0;
}
