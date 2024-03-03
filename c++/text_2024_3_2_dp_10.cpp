#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //创建dp表
        //初始化
        //填表
        //返回值
        int m = dungeon.size() + 1;
        int n = dungeon[0].size() + 1;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[m - 1][n - 2] = dp[m - 2][n - 1] = 1;
        for (int i = m - 2;i >= 0;i--)
            for (int j = n - 2;j >= 0;j--)
            {
                if (dungeon[i][j] < 0)dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                else
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                    if (dp[i][j] < 1)dp[i][j] = 1;
                }
            }

        return dp[0][0];

    }
};
int main()
{
	return 0;
}