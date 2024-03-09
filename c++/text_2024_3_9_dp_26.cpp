#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vector<int> dp(n, 1);
        for (int i = 1;i < n;i++)
        {
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
                dp[i] += dp[i - 1];
        }
        int Size = 26;
        vector<int> arr(Size);
        for (int i = 0;i < n;i++)
        {
            arr[s[i] - 'a'] = max(arr[s[i] - 'a'], dp[i]);
        }
        int Sum = 0;
        for (auto e : arr)
        {
            Sum += e;
        }
        return Sum;
    }
};
int main()
{
	return 0;
}