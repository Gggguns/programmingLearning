#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //创建dp
        //初始化
        //填表
        //返回结果
        int n = nums.size() + 1;
        vector<int> f(n, 1);
        auto g = f;
        for (int i = 1;i < n;i++)
        {
            f[i] = max(nums[i - 1], max(nums[i - 1] * f[i - 1], nums[i - 1] * g[i - 1]));
            g[i] = min(nums[i - 1], min(nums[i - 1] * f[i - 1], nums[i - 1] * g[i - 1]));
        }
        int Max = f[1];
        for (int i = 1;i < n;i++)
            if (Max < f[i])Max = f[i];
        return Max;
    }
};
int main()
{
	return 0;
}