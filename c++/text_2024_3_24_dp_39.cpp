#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int Max = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1;0 <= i;i--)
            for (int j = i;j < n;j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i < 3)dp[i][j] = j - i + 1;
                    else dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
                Max = max(Max, dp[i][j]);
            }
        return Max;
    }
};
int main()
{
	return 0;
}