#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s)
    {
        //创建dp表
        //初始化
        //填表
        //返回值
        int n = s.size();
        vector<long> dp(n);
        if (n == 0)return 0;

        if (s[0] != '0')dp[0] = 1;
        else return 0;

        if (n == 1) return dp[0];

        if (s[1] != '0')dp[1] = 1;
        if ('1' <= s[0] && s[0] <= '2')
        {
            if (s[0] == '1')dp[1] += 1;
            if (s[0] == '2' && s[1] <= '6')dp[1] += 1;
        }

        for (int i = 2;i < n;i++)
        {
            if (s[i] != '0')
                dp[i] += dp[i - 1];
            if ('1' <= s[i - 1] && s[i - 1] <= '2')
            {
                if (s[i - 1] == '1')dp[i] += dp[i - 2];
                if (s[i - 1] == '2' && s[i] <= '6')dp[i] += dp[i - 2];
            }
        }



        return dp[n - 1];
    }
};
int main()
{
    string s;
    cin >> s;
    Solution S;
    cout << S.numDecodings(s);
	return 0;
}