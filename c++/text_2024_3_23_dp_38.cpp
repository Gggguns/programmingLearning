#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1;i >= 0;i--)
            for (int j = i;j < n;j++)
                dp[i][j] = s[i] == s[j] ? j - i < 3 ? true : dp[i + 1][j - 1] : false;
        vector<int> v(n, INT_MAX);
        for (int i = 0;i < n;i++)
        {
            if (dp[0][i])v[i] = 0;
            else
            {
                for (int j = 0;j <= i;j++)
                    if (dp[j][i])
                        v[i] = min(v[i], v[j - 1] + 1);
            }
        }
        return v[n - 1];
    }
};
int main()
{
	return 0;
	
}