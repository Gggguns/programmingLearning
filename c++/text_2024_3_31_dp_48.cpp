#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int Ret = 0;
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                Ret = max(Ret, dp[i][j]);
            }
        }
        return Ret;
    }
};
int main()
{
    vector<int> nums1{ 1,2,3,2,1 };
    vector<int> nums2{ 3,2,1,4,7 };
    Solution s;
    cout<<s.findLength(nums1, nums2);
	return 0;
}