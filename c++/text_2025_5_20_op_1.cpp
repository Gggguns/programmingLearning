#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = nums.size() - 1;
        tempNums.resize(size);
        tempIndex.resize(size);
        index.resize(size);
        ret.resize(size);
        for (int i = 0; i < size; i++)index[i] = i;
        mergeSort(nums, left, right);
        return ret;
    }
    void mergeSort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = (left + right) / 2;
        // ·Ö¸î
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        int start1 = left, end1 = mid + 1;
        int start2 = mid + 1, end2 = right + 1;
        int end = left;
        while (start1 < end1 && start2 < end2)
        {
            if (nums[start1] > nums[start2])
            {
                tempNums[end] = nums[start2];
                tempIndex[end++] = index[start2++];
            }
            else
            {
                ret[index[start1]] += (start2 - end1);
                tempNums[end] = nums[start1];
                tempIndex[end++] = index[start1++];
            }
        }
        while (start1 < end1)
        {
            ret[index[start1]] += (end2 - end1);
            tempNums[end] = nums[start1];
            tempIndex[end++] = index[start1++];
        }
        while (start2 < end2)
        {
            tempNums[end] = nums[start2];
            tempIndex[end++] = index[start2++];
        }

        // ¿½±´
        for (int i = left; i <= right; i++)
        {
            nums[i] = tempNums[i];
            index[i] = tempIndex[i];
        }
    }
    vector<int> ret;
    vector<int> index;
    vector<int> tempNums;
    vector<int> tempIndex;
};
int main()
{
    vector<int> nums = { 2, 0, 1 };
    Solution s;
    s.countSmaller(nums);
	return 0;
}