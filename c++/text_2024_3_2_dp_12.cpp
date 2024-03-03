#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)return 0;
        if (n == 1)return nums[0];
        if (n == 2)return max(nums[0], nums[1]);
        vector<int> f1(n);
        vector<int> g1(n);
        f1[0] = nums[0];
        for (int i = 1;i < n - 1;i++)
        {
            f1[i] = g1[i - 1] + nums[i];
            g1[i] = max(f1[i - 1], g1[i - 1]);
        }
        vector<int> f2(n);
        vector<int> g2(n);
        for (int i = 1;i < n;i++)
        {
            f2[i] = g2[i - 1] + nums[i];
            g2[i] = max(f2[i - 1], g2[i - 1]);
        }
        return max(max(g1[n - 2], f1[n - 2]), max(g2[n - 1], f2[n - 1]));
    }

};
int main()
{
	return 0;
}