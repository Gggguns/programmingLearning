#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //创建dp表
        //初始化
        //填表
        //返回结果
        int n = nums.size();
        if (n <= 2)return 0;
        vector<int> dp(n);

        for (int i = 2;i < n;i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }
        int SumRet = 0;
        for (auto e : dp)
        {
            SumRet += e;
        }
        return SumRet;
    }
};
int main()
{
    return 0;
}