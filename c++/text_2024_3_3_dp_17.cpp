#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //创建dp表
        //初始化
        //填表
        //返回值
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(3));
        auto g = f;
        f[0][0] = -prices[0];
        g[0][1] = g[0][2] = f[0][1] = f[0][2] = -0x3f3f3f3f;
        for (int i = 1;i < n;i++)
        {
            for (int j = 0;j < 3;j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                if (j - 1 >= 0)
                    g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
                else
                    g[i][j] = g[i - 1][j];
            }
        }

        int Max = 0;
        for (int i = 0;i < 3;i++)
        {
            if (f[n - 1][i] > Max)Max = f[n - 1][i];
            if (g[n - 1][i] > Max)Max = g[n - 1][i];
        }
        return Max;
    }

};
int main()
{
	return 0;
}