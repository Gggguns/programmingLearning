#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int left = 0, right = n - 1;
        vector<vector<int>>v;
        while (n > 1)
        {
            while (left < right)
            {
                long Sum = nums[left] + nums[right] + nums[n];
                if (Sum == 0)
                {
                    v.push_back({ nums[left],nums[right],nums[n] });
                    left++;
                    while (left < right && nums[left] == nums[left - 1])left++;
                    right--;
                    while (left < right && nums[right] == nums[right + 1])right--;
                }
                else if (Sum > 0)
                {
                    if (nums[left] > nums[right])left++;
                    else right--;
                }
                else
                {
                    if (nums[left] > nums[right])right--;
                    else left++;
                }
            }
            n--;
            while (n >= 0 && nums[n] == nums[n + 1])n--;
            left = 0;
            right = n - 1;
        }
        return v;
    }
};
int main()
{
    Solution s;
    vector<int> nums{ -1,0,1,2,-1,-4 };
    s.threeSum(nums);
	return 0;
}