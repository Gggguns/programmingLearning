#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0)return 0;
        int left = -1, right = nums.size() - 1, mid = 0;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (nums[mid] > target)right = mid - 1;
            else left = mid;
        }
        if (left >= 0 && nums[left] == target)return left;
        else return left + 1;
    }
};
int main()
{
	return 0;
}