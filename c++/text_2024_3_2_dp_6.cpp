#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //创建dp表
        //初始化
        //填表
        //返回值
        int m = 0, n = 0;
        m = obstacleGrid.size() + 1;
        n = obstacleGrid[0].size() + 1;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][1] = 1;
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n;j++)
            {
                if (obstacleGrid[i - 1][j - 1] != 0)dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

            }
        return dp[m - 1][n - 1];
    }
};
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> obstacleGrid(m,vector<int>(n));
    for(auto e1:obstacleGrid)
        for (auto e2 : e1)
        {
            cin >> e2;
        }

    Solution s;
    cout<<s.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}