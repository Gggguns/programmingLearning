#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size = nums.size();
        int sum = 0;
        int tempsum = 0;
        for (auto e : nums) sum += e;
        int left = -1, right = 0, result = 0;
        int target = sum - x;
        int ret = size + 1;
        if (target < 0) return -1;
        while (right < size)
        {
            tempsum += nums[right++];
            while (tempsum > target)
            {
                left++;
                tempsum -= nums[left];
            }
            if (tempsum == target)
            {
                result = size - (right - left - 1);
                ret = min(ret, result);
            }
        }
        if (ret > size) return -1;
        else return ret;
    }
};

int main()
{
    return 0;
}