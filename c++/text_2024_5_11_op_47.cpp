#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void qsort(vector<int>& nums, int left, int right) {
        if (left >= right)return;
        int mid = left + (right - left) / 2, sz = right - left + 1;
        int lbegin = left, rbegin = mid + 1;
        qsort(nums, left, mid);
        qsort(nums, mid + 1, right);
        vector<int> temp;
        while (lbegin <= mid && rbegin <= right) {
            if (nums[lbegin] < nums[rbegin])temp.push_back(nums[lbegin++]);
            else temp.push_back(nums[rbegin++]);
        }
        while (lbegin <= mid)temp.push_back(nums[lbegin++]);
        while (rbegin <= right)temp.push_back(nums[rbegin++]);
        for (int i = 0;i < sz;i++) {
            nums[left + i] = temp[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
};
int main() {
    return 0;
}