#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size - 1;
        temp.resize(size);
        mergeSort(nums, left, right);
        return ret;
    }
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int start1 = left, end1 = mid + 1;
        int start2 = mid + 1, end2 = right + 1;
        int end = left;
        // º∆À„
        int cur1 = left, cur2 = mid + 1;
        while (cur1 < end1 && cur2 < end2)
        {
            if (nums[cur1] > nums[cur2] * 2.0)
            {
                ret += (end1 - cur1);
                cur2++;
            }
            else cur1++;
        }
        // ∫œ≤¢
        while (start1 < end1 && start2 < end2)
        {
            if (nums[start1] > nums[start2])
            {
                temp[end++] = nums[start2++];
            }
            else
                temp[end++] = nums[start1++];
        }
        while (start1 < end1) temp[end++] = nums[start1++];
        while (start2 < end2) temp[end++] = nums[start2++];

        // øΩ±¥
        for (int i = left; i <= right; i++) nums[i] = temp[i];

    }
    int ret = 0;
    vector<int> temp;
};
int main()
{
    Solution s;
    vector<int> nums = { 1,3,2,3,1 };
    cout << s.reversePairs(nums);
	return 0;
}