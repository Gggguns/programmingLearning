#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid + 1] >= nums[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1 };
    s.findPeakElement(nums);
	return 0;
}