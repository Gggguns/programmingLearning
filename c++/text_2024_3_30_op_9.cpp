#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = -1, right = 0;
        int Min = nums.size() + 1;
        int n = nums.size();
        long long Sum = nums[0];
        while (left < right && right < n) {
            if (Sum < target) {
                right++;
                if (right < n)
                    Sum += nums[right];
            }
            else {
                Min = min(Min, right - left);
                Sum -= nums[++left];
            }
        }
        if (Min > n)return 0;
        else return Min;
    }
};
int main()
{
    Solution s;
    vector<int> nums{ 1,2,3,4,5 };
    s.minSubArrayLen(15, nums);
	return 0;
}