#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int Max = nums[0], Min = nums[0];
        for (auto e : nums)
        {
            if (Max < e)Max = e;
            if (Min > e)Min = e;
        }
        int n = Max - Min + 1;
        vector<int> Nums(n);
        for (auto e : nums)
        {
            Nums[e - Min]++;
        }
        vector<int> f(n);
        vector<int> g(n);
        f[0] = Nums[0] * Min;
        for (int i = 1;i < n;i++)
        {
            f[i] = g[i - 1] + Nums[i] * (i + Min);
            g[i] = max(g[i - 1], f[i - 1]);
        }
        return max(f[n - 1], g[n - 1]);
    }
};
int main()
{
    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (auto& e : nums)
    {
        cin >> e;
    }
    Solution s;
    cout << s.deleteAndEarn(nums);
	return 0;
}