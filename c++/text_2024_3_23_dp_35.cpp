#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int Sum = 0;
        for (int i = n - 1;i >= 0;i--)
        {
            for (int j = i;j < n;j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i < 3)dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                else dp[i][j] = false;
                if (dp[i][j])Sum++;
            }
        }
        return Sum;
    }
};
int main()
{
    string str = "abc";
    Solution s;
    s.countSubstrings(str);
	return 0;
}