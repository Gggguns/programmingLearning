#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        int MOL = 1e9 + 7;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 0;i < n1 + 1;i++)dp[i][0] = 1;
        for (int i = 1;i < n1 + 1;i++)
        {
            for (int j = 1;j < n2 + 1;j++)
            {
                if (s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1];
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOL;
            }
        }
        return dp[n1][n2];
    }
};
int main()
{
    Solution s;
    s.numDistinct("babgbag","bag");
	return 0;
}