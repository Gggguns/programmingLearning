#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        int Max = 1;
        string str;
        str += s[0];
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
                if (dp[i][j])
                {
                    if (Max < j - i + 1)
                    {
                        Max = j - i + 1;
                        str = s.substr(i, j - i + 1);
                    }
                }
            }

        }
        return str;
    }
};
int main()
{
    return 0;
}