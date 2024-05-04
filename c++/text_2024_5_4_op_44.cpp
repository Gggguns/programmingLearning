#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int getRomdon(int left, int right) {
        int Rom = rand();
        return (Rom % (right - left + 1) + left);
    }
    void qsort(vector<int>& nums, int left, int right) {
        if (left >= right)return;
        int key = nums[getRomdon(left, right)];
        int cur = left;
        int begin = left, end = right;
        while (cur <= right) {
            if (nums[cur] < key) {
                swap(nums[cur], nums[left]);
                left++;
                if (cur < left)cur = left;
            }
            else if (nums[cur] == key)cur++;
            else {
                swap(nums[cur], nums[right]);
                right--;
            }
        }
        qsort(nums, begin, left - 1);
        qsort(nums, right + 1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
};
int main() {
    return 0;
}