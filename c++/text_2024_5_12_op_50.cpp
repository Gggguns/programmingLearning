#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int Merger(vector<int>& nums, int left, int right) {
        if (left >= right)return 0;
        int Sum = 0, mid = left + (right - left) / 2;
        //划分区域
        Sum += Merger(nums, left, mid);
        Sum += Merger(nums, mid + 1, right);
        int sz = right - left + 1, lbegin = left, rbegin = mid + 1;
        while (lbegin <= mid) {
            while (rbegin <= right && nums[lbegin] / 2.0 <= nums[rbegin])rbegin++;
            if (rbegin <= right)Sum = Sum + right - rbegin + 1;
            else break;
            lbegin++;
        }
        //合并两个有序区间
        lbegin = left;
        rbegin = mid + 1;
        vector<int> temp;
        int cp = rbegin;
        while (lbegin <= mid && rbegin <= right) {
            if (nums[lbegin] > nums[rbegin]) {
                temp.push_back(nums[lbegin++]);
            }
            else temp.push_back(nums[rbegin++]);
        }
        while (lbegin <= mid)temp.push_back(nums[lbegin++]);
        while (rbegin <= right)temp.push_back(nums[rbegin++]);
        for (int i = 0;i < sz;i++) {
            nums[left + i] = temp[i];
        }
        return Sum;
    }
    int reversePairs(vector<int>& nums) {
        return Merger(nums, 0, nums.size() - 1);
    }
};
int main() {
    return 0;
}