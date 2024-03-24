#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1));
        dp[0][0] = true;
        for (int i = 1;i < n2 + 1;i++)
        {
            if (p[i - 1] == '*')dp[0][i] = dp[0][i - 1];
            else dp[0][i] = false;
        }

        for (int i = 1;i < n1 + 1;i++)
            for (int j = 1;j < n2 + 1;j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    if (dp[i][j - 1] || dp[i - 1][j])dp[i][j] = true;
                    else dp[i][j] = false;
                }
                else dp[i][j] = false;
            }

        return dp[n1][n2];
    }
};
int main()
{
    Solution s;
    s.isMatch("abcabczzzde", "*abc???de*");
	return 0;
}