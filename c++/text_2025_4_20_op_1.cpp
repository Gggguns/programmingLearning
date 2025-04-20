#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        if (nums[right] < target) return right + 1;
        if (nums[left] > target) return left;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};
int main()
{
    return 0;
}