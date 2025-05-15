#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int left = -1, right = size, cur = 0;
        while (cur < right)
        {
            if (nums[cur] == 0)
            {
                left++;
                swap(nums[left], nums[cur++]);
            }
            else if (nums[cur] == 2)
            {
                right--;
                swap(nums[right], nums[cur]);
            }
            else cur++;
        }
    }
};
int main()
{
    vector<int> nums = { 2,0,2,1,1,0 };
    Solution s;
    s.sortColors(nums);
    return 0;
}