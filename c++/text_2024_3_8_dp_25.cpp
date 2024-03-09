#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        s = ' ' + s;
        unordered_set<string> hash;
        for (auto e : wordDict)
        {
            hash.insert(e);
        }
        int n = s.size();
        vector<bool> dp(n);
        dp[0] = true;
        for (int i = 1;i < n;i++)
        {
            for (int j = i;j >= 1;j--)
            {
                if (dp[j - 1] && hash.count(s.substr(j, i - j + 1)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n - 1];
    }
};

int main()
{
	return 0;
}