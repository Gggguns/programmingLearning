#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = size - 1;
            int target = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    results.push_back({ nums[i], nums[left], nums[right] });
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
                else if (nums[left] + nums[right] < target)left++;
                else right--;

            }
        }
        return results;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 0,0,0,0 };
    s.threeSum(nums);
    return 0;
}