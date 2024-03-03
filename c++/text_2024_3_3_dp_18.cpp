#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> f(n, vector<int>(k + 1, -0x3f3f3f3f));
        auto g = f;
        g[0][0] = 0;f[0][0] = -prices[0];
        for (int i = 1;i < n;i++)
            for (int j = 0;j < k + 1;j++)
            {
                f[i][j] = max(f[i - 1][j], g[i - 1][j] - prices[i]);
                if (j - 1 >= 0)
                    g[i][j] = max(g[i - 1][j], f[i - 1][j - 1] + prices[i]);
                else
                    g[i][j] = g[i - 1][j];
            }
        int Max = f[n - 1][0];
        for (int i = 0;i < k + 1;i++)
        {
            if (g[n - 1][i] > Max)Max = g[n - 1][i];
        }
        return Max;
    }
};
int main()
{
    int k;
    int n;
    cin >> n >> k;
    vector<int> prices(n);
    for (auto& e : prices)
    {
        cin >> e;
    }
    Solution s;
    cout<<endl<<s.maxProfit(k, prices)<<endl;
	return 0;
}