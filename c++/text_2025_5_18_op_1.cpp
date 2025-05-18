#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        temp.resize(size);
        int left = 0, right = size - 1;
        srand(time(nullptr));
        mergeSort(nums, left, right);
        return nums;
    }
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right)return;
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int start1 = left, end1 = mid + 1;
        int start2 = mid + 1, end2 = right + 1;
        int end = left;
        // ºÏ²¢
        while (start1 < end1 && start2 < end2)
        {
            if (nums[start1] > nums[start2])temp[end++] = nums[start2++];
            else temp[end++] = nums[start1++];
        }
        while (start1 < end1)temp[end++] = nums[start1++];
        while (start2 < end2)temp[end++] = nums[start2++];
        
        for (int i = left; i <= right; i++)nums[i] = temp[i];

    }
    vector<int> temp;
};
int main()
{
    Solution s;
    vector<int> nums = { 5,1,1,2,0,0 };
    s.sortArray(nums);
	return 0;
}