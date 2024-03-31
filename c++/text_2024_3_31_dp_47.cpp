#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));

        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (s1[i - 1] == s2[j - 1])dp[i][j] = max(dp[i][j], s1[i - 1] + dp[i - 1][j - 1]);
            }


        long long Sum = 0;
        for (int i = 0;i < n;i++)Sum += s1[i];
        for (int i = 0;i < m;i++)Sum += s2[i];
        return Sum - 2 * dp[n][m];
    }
};

int main()
{
    Solution s;
    s.minimumDeleteSum("delete", "leet");
	return 0;
}