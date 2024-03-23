#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int Max = 0, n = arr.size();
        vector<vector<int>>dp(n, vector<int>(n, 2));
        unordered_map<int, int> hash;
        for (int i = 0;i < n;i++)
        {
            hash[arr[i]] = i;
        }
        for (int i = 1;i < n;i++)
        {
            for (int j = n - 1;j > i;j--)
            {
                if (hash.count(arr[j] - arr[i]) && ((hash[arr[j] - arr[i]]) < i))
                    dp[i][j] = max(dp[hash[arr[j] - arr[i]]][i] + 1, dp[i][j]);
                else continue;
                Max = max(Max, dp[i][j]);
            }
        }
        if (Max < 3)return 0;
        else return Max;
    }
};
int main()
{
	unordered_map<int, int> hash;
	cout << hash[1];
	return 0;
}