#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //创建dp表
        //初始化
        //填表
        //返回值
        int m = grid.size() + 1;
        int n = grid[0].size() + 1;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][1] = 0;
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        return dp[m - 1][n - 1];
    }
};
int main()
{
	return 0;
}