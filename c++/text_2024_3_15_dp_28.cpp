#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n);
        auto g = f;
        f[0] = 1, g[0] = 1;
        int MaxRet = f[0];
        for (int i = 1;i < n;i++)
        {
            for (int j = 0;j < i;j++)
            {
                if (nums[i] > nums[j])
                    g[i] = max(g[i], f[j] + 1);
                if (nums[i] < nums[j])
                    f[i] = max(f[i], g[j] + 1);
                MaxRet = max(MaxRet, max(g[i], f[i]));
            }
        }
        return MaxRet;
    }
};
int main()
{
	return 0;
}