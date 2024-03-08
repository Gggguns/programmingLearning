#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        //创建dp表
        //初始化
        //填表
        //返回结果
        int n = arr.size();
        vector<int> f(n, 1);
        auto g = f;
        int MaxRet = f[0];
        for (int i = 1;i < n;i++)
        {
            if (arr[i] > arr[i - 1])
            {
                f[i] = g[i - 1] + 1;
                MaxRet = max(f[i], MaxRet);
            }
            if (arr[i] < arr[i - 1])
            {
                g[i] = f[i - 1] + 1;
                MaxRet = max(g[i], MaxRet);
            }
        }
        return MaxRet;
    }
};
int main()
{
	return 0;
}