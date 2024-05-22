#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int BinaryFind(int num) {
        int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] >= num)right = mid;
            else left = mid + 1;
        }
        return right;
    }
    int LIS(vector<int>& a) {
        int Max = -1, n = a.size();
        for (int i = 0;i < n;i++) {
            int x = a[i];
            if (nums.size() == 0 || x > nums.back()) {
                nums.push_back(x);
            }
            else {
                int Ret = BinaryFind(x);
                nums[Ret] = x;
            }
        }
        return nums.size();
    }
    vector<int> nums;
};
int main() {
    vector<int> nums = { 1, 4, 7, 5, 6 };
    Solution s;
    s.LIS(nums);
    return 0;
}