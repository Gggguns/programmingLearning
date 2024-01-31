#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        //创建dp表
        //初始化
        //填表
        //处理细节
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = dp[2] = 1;

        int i = 3;
        for (i = 3;i < n + 1;i++)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        return dp[n];
    }
};
int main()
{
    int n = 0;
    cin >> n;
    Solution S;
    cout << S.tribonacci(n);
	return 0;
}