#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
       
        //创建dp表
        //初始化
        //填表
        //返回值
        int n = cost.size();
        vector<int> dp(n + 1);
        if (n < 2)return 0;
        dp[0] = dp[1] = 0;
        for (int i = 2;i < n + 1;i++)
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        return dp[n];
    }
};

int main()
{
    int n = 0;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0;i < n;i++)
    {
        cin >> cost[i];
    }
    Solution S;
    cout<<S.minCostClimbingStairs(cost);
    return 0;
}