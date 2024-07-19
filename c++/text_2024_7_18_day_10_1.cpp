#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int getLongestPalindrome(string A) {
        A = ' ' + A;
        int size = A.size();
        int ret = 0;
        vector<vector<bool>> dp(size, vector<bool>(size));
        for (int i = size - 1;i > 0;i--) {
            for (int j = i;j < size;j++) {
                if (A[i] == A[j]) {
                    if (j - i < 3)dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                else dp[i][j] = false;
                if (dp[i][j] && j - i + 1 > ret) {
                    ret = j - i + 1;
                }
            }
        }
        return ret;
    }
};
int main() {
    return 0;
}