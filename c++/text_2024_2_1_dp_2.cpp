#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    unsigned long waysToStep(int n) {
        //创建dp
        //处理边界
        //填表
        const int MOD = 1e9 + 7;
        if (n < 3)return n;
        vector<unsigned long> dp(n, 0);
        dp[0] = 1;dp[1] = 2;dp[2] = 4;
        for (int i = 3;i < n;i++)
            dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
        return dp[n - 1];
    }
};
int main()
{
    Solution S;
    int n = 0;
    cin >> n;
    unsigned long res = S.waysToStep(n);
    cout << res;
	return 0;
}