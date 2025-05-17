#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        srand(time(nullptr));
        return qsort(nums, left, right, k);

    }
    int qsort(vector<int>& nums, int left, int right, int k)
    {
        if (left > right)return -1;
        int key = nums[rand() % (right - left + 1) + left];
        int start = left, end = right;
        int cur = left;
        while (cur <= right)
        {
            if (nums[cur] < key)
            {
                swap(nums[right--], nums[cur]);
            }
            else if (nums[cur] > key)
            {
                swap(nums[left++], nums[cur++]);
            }
            else cur++;
        }
        int a = left - start, b = cur - left;
        if (k > a + b)return qsort(nums, right + 1, end, k - a - b);
        else if (k > a) return key;
        else return qsort(nums, start, left - 1, k);
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 3,2,3,1,2,4,5,5,6 };
    int k = 4;
    cout << s.findKthLargest(nums, k);
	return 0;
}