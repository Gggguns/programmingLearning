#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        unordered_map<long long, vector<int>> hash;
        for (int i = 0;i < n;i++)hash[nums[i]].push_back(i);
        int Count = 0;
        for (int i = 1;i < n;i++)
        {
            for (int j = n - 1;j > i;j--)
            {
                long long a = (long long)nums[i] * 2 - nums[j];
                if (hash.count(a))
                {
                    int Size = hash[a].size();
                    auto v = hash[a];
                    for (int h = 0;h < Size;h++)
                    {
                        if (v[h] < i)
                        {
                            dp[i][j] += dp[v[h]][i] + 1;
                        }
                        else break;
                    }
                }
                Count += dp[i][j];
            }
        }
        return Count;
    }
};
int main()
{
    vector<int> nums{ 7,7,7,7,7 };
    Solution s;
    s.numberOfArithmeticSlices(nums);
	return 0;
}

