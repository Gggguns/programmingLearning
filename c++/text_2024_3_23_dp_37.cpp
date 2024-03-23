#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1;i >= 0;i--)
        {
            for (int j = i;j < n;j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i + 1 < 3)dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                else dp[i][j] = false;
            }
        }
        for (int i = 0;i < n - 1;i++)
        {
            for (int j = i;j < n - 1;j++)
            {
                if (dp[0][i] && dp[i + 1][j] && dp[j + 1][n - 1])
                    return true;
            }
        }
        return false;
    }
};
int main()
{
	return 0;
}