#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), len = s3.size();
        if (len != n + m)return false;
        s1 = ' ' + s1;
        s2 = ' ' + s2;
        s3 = ' ' + s3;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 1;i <= n;i++)
            if (s1[i] == s3[i])dp[i][0] = dp[i - 1][0];
            else break;
        for (int i = 1;i <= m;i++)
            if (s2[i] == s3[i])dp[0][i] = dp[0][i - 1];
            else break;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                dp[i][j] = (s1[i] == s3[i + j] && dp[i - 1][j]) || (s2[j] == s3[i + j] && dp[i][j - 1]);
        
        for (auto e1 : dp)
        {
            for (auto e2 : e1)
                cout << e2 << ' ';
            cout << endl;
        }
        return dp[n][m];
    }
};
int main()
{
    Solution s;
    s.isInterleave("aabc", "abad", "aabadabc");
	return 0;
}
