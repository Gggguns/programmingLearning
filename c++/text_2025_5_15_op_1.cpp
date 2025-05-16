#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        srand(time(nullptr));
        qsort(nums, left, right);
        return nums;
    }
    void qsort(vector<int>& nums, int left, int right)
    {
        if (left >= right)return;
        int start = left, end = right;
        int key = nums[rand() % (right - left + 1) + left];
        int cur = left;
        while (cur <= right)
        {
            if (nums[cur] > key)
            {
                swap(nums[right--], nums[cur]);
            }
            else if (nums[cur] < key)
            {
                swap(nums[left], nums[cur]);
                left++;
                cur++;
            }
            else cur++;
        }
        int x = 0;
        qsort(nums, start, left - 1);
        qsort(nums, right + 1, end);
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 5,2,3,1};
    s.sortArray(nums);
	return 0;
}