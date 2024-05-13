#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        s = ' ' + s;
        int n = s.size();
        int Max = 0;
        string Ret;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1;i >= 1;i--) {
            for (int j = i;j < n;j++) {
                if (s[i] == s[j]) {
                    if (j - i < 3)dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                int lenth = j - i + 1;
                if (dp[i][j] && lenth > Max) {
                    Max = lenth;
                    Ret = s.substr(i, lenth);
                }
            }
        }
        return Ret;
    }
};

int main() {
    Solution s;
    s.longestPalindrome("cbbd");
    return 0;
}