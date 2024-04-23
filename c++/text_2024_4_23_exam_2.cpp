#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int MLS(vector<int>& arr) {
        vector<int> v(arr);
        sort(v.begin(), v.end());
        int sz = v.size();
        vector<int> dp(sz, 1);
        int Max = 0;
        for (int i = 1;i < sz;i++) {
            if (v[i] == v[i - 1] + 1)dp[i] = dp[i - 1] + 1;
            if (v[i] == v[i - 1])dp[i] = dp[i - 1];
            Max = max(Max, dp[i]);
        }
        return Max;
    }
};
int main() {
	return 0;
}