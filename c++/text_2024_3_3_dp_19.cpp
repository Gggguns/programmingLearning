#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //创建dp表
        //初始化
        //填表
        //返回结果
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1;i < n;i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        int Max = dp[0];
        for (auto e : dp)
        {
            if (e > Max)Max = e;
        }
        return Max;
    }
};
int main()
{
	return 0;
}