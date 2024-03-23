#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        unordered_map<int, int> hash;
        hash[nums[0]] = 0;
        int Max = 2;
        for (int i = 1;i < n;i++)
        {
            for (int j = n - 1;j > i;j--)
            {
                int a = 2 * nums[i] - nums[j];
                if (hash.count(a) && hash[a] < i)
                    dp[i][j] = max(dp[i][j], dp[hash[a]][i] + 1);
                Max = max(Max, dp[i][j]);
            }
            hash[nums[i]] = i;
        }
        return Max;
    }
};
int main()
{
    return 0;
}