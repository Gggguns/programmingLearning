#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)return { -1, -1 };
        int start = -1, end = -1;
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[mid] >= target) right = mid;
            else left = mid + 1;
        }
        if (nums[left] == target) start = left;
        else return { -1, -1 };
        left = 0, right = nums.size() - 1;
        while (left < right)
        {
            mid = (left + right) / 2 + 1;
            if (nums[mid] <= target) left = mid;
            else right = mid - 1;
        }
        end = right;
        return { start, end };
    }
};
int main()
{
    return 0;
}