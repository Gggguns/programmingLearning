#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //创建dp表
        //初始化
        //填表
        //返回值
        int m, n;
        m = matrix.size() + 1;
        n = matrix.size() + 2;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (auto& e : dp[0])
            e = 0;
        for (int i = 1;i < m;i++)
            for (int j = 1;j < n - 1;j++)
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
        int min = INT_MAX;
        for (int i = 1;i < n - 1;i++)
            if (dp[m - 1][i] < min)min = dp[m - 1][i];
        return min;
    }
};
int main()
{
	return 0;
}