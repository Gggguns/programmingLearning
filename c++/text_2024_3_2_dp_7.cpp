#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        //创建dp表
        //初始化
        //填表
        //返回值
        int m, n;
        m = frame.size() + 1;
        n = frame[0].size() + 1;
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
        return dp[m - 1][n - 1];
    }
};
int main()
{
	return 0;
}