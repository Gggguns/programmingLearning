#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> Index, Ret;
    void Merger(vector<int>& nums, int left, int right) {
        if (left >= right)return;
        int mid = left + (right - left) / 2;
        Merger(nums, left, mid);
        Merger(nums, mid + 1, right);
        int lbegin = left, rbegin = mid + 1, sz = right - left + 1;
        vector<int> temp, tempi;
        while (lbegin <= mid && rbegin <= right) {
            if (nums[lbegin] > nums[rbegin]) {
                int Res = right - rbegin + 1;
                Ret[Index[lbegin]] += Res;
                temp.push_back(nums[lbegin]);
                tempi.push_back(Index[lbegin++]);
            }
            else {
                temp.push_back(nums[rbegin]);
                tempi.push_back(Index[rbegin++]);
            }
        }
        while (lbegin <= mid) {
            temp.push_back(nums[lbegin]);
            tempi.push_back(Index[lbegin++]);
        }
        while (rbegin <= right) {
            temp.push_back(nums[rbegin]);
            tempi.push_back(Index[rbegin++]);
        }
        for (int i = 0;i < sz;i++) {
            nums[left + i] = temp[i];
            Index[left + i] = tempi[i];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        Ret.resize(sz);
        for (int i = 0;i < sz;i++)Index.push_back(i);
        Merger(nums, 0, sz - 1);
        return Ret;
    }
};
int main() {
	return 0;
}