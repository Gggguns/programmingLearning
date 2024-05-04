#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;
class Solution {
public:
    int getRoman(int left, int right) {
        return (rand() % (right - left + 1) + left);
    }
    void qsort(vector<int>& nums, int left, int right, int k) {
        if (left >= right || k == 0)return;
        int key = nums[getRoman(left, right)];
        int begin = left, end = right;
        int cur = left;
        left--;
        right++;
        while (cur < right) {
            if (nums[cur] > key)swap(nums[++left], nums[cur++]);
            else if (nums[cur] == key)cur++;
            else swap(nums[cur], nums[--right]);
        }
        int a = left - begin + 1;
        int b = right - left - 1;
        if (a >= k)qsort(nums, begin, left, k);
        else if (a + b >= k)return;
        else qsort(nums, right, end, k - a - b);
    }
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(NULL));
        qsort(nums, 0, nums.size() - 1, k);
        return nums[k - 1];
    }
};
int main() {
    Solution s;
    vector<int> nums = { 3,2,1,5,6,4 };
    s.findKthLargest(nums, 2);
	return 0;
}