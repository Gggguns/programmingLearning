#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0x3ffff));
        for (int i = n - 1;i >= 0;i--)
            for (int j = i;j < n;j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i < 3)dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        return dp[0][n - 1];
    }
};
int main()
{
    string str("mbadm");
    Solution s;
    s.minInsertions(str);
	return 0;
}