#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //创建dp
        //初始化
        //填表
        //返回结果
        int n = nums.size();
        vector<int> f(n);
        auto g = f;
        int sum = nums[0];
        f[0] = nums[0];
        g[0] = min(g[0], 0);
        for (int i = 1;i < n;i++)
        {
            sum += nums[i];
            f[i] = max(f[i - 1] + nums[i], nums[i]);
            g[i] = min(g[i - 1] + nums[i], nums[i]);
        }
        int Max = f[0], Min = g[0];
        for (int i = 0;i < n;i++)
        {
            if (Max < f[i])Max = f[i];
            if (Min > g[i])Min = g[i];
        }
        return max(Max, sum - Min);
    }
};
int main()
{
	return 0;
}
