#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < size; )
            {
                int result = nums[i] + nums[j];
                int left = j + 1;
                int right = size - 1;
                while (left < right)
                {
                    if ((long long)nums[left] + nums[right] + result > target) right--;
                    else if ((long long)nums[left] + nums[right] + result < target) left++;
                    else
                    {
                        ret.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        left++;
                        right--;
                        // 去重
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
                j++;
                // 出重
                while (j < size && nums[j] == nums[j - 1]) j++;
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1,0,-1,0,-2,2 };
    s.fourSum(nums, 0);
    return 0;
}