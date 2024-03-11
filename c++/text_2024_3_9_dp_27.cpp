#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int MaxRet = 1;
        for (int i = 1;i < n;i++)
        {
            for (int j = i;j >= 0;j--)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            MaxRet = max(MaxRet, dp[i]);
        }
        return MaxRet;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto& e : nums)
    {
        cin >> e;
    }
    Solution s;
    cout << s.lengthOfLIS(nums);
    return 0;
}