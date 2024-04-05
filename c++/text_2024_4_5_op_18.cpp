#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)return { -1,-1 };
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        int begin = -1, end = -1;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= target)right = mid;
            else left = mid + 1;
        }
        if (nums[left] == target)begin = left;
        else return{ begin,end };
        left = 0, right = nums.size() - 1;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (nums[mid] > target)right = mid - 1;
            else left = mid;
        }
        return { begin,right };
    }
};
int main()
{
	int i = 1;
	i =1+ 0.5;
	cout << i;

	return 0;
}