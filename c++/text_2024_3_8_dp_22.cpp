#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        //创建dp表
        //初始化
        //填表
        //返回结果
        int n = nums.size();
        vector<int> f(n);
        auto g = f;
        if (nums[0] > 0)
        {
            f[0] = 1;
            g[0] = 0;
        }
        else if (nums[0] == 0)
        {
            f[0] = 0;
            g[0] = 0;
        }
        else
        {
            f[0] = 0;
            g[0] = 1;
        }
        int MaxRet = f[0];
        for (int i = 1;i < n;i++)
        {
            if (nums[i] > 0)
            {
                f[i] = f[i - 1] + 1;
                if (g[i - 1])
                    g[i] = g[i - 1] + 1;
            }
            else if (nums[i] == 0)
            {
                f[i] = 0;
                g[i] = 0;
            }
            else
            {
                if (g[i - 1])
                    f[i] = g[i - 1] + 1;
                g[i] = f[i - 1] + 1;
            }
            MaxRet = max(f[i], MaxRet);
        }
        return MaxRet;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v)
    {
        cin >> e;
    }
    Solution s;
    cout << s.getMaxLen(v);
    return 0;
}