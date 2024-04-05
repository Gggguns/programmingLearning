#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        long long mid = 0, left = 0, right = nums.size() - 1;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < nums[right])right = mid;
            else left = mid + 1;
        }
        return nums[right];
    }
};
int main()
{
	return 0;
}