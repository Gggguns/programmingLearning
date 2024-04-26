#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getLongestPalindrome(string A) {
        int Ret = -0x3ffff;
        int n = A.size();
        int m = A.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        for (int i = n;i >= 1;i--) {
            for (int j = i;j <= m;j++) {
                if (A[i - 1] == A[j - 1]) {
                    if (j - i < 3)dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j])Ret = max(Ret, j - i + 1);
            }
        }
        return Ret;
    }
};
int main()
{
    Solution s;
    s.getLongestPalindrome("abbba");
	return 0;
}