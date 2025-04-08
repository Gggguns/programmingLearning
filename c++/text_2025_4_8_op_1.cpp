#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = -1, right = 0;
        long long sum = 0;
        int minlength = nums.size();
        int size = nums.size();
        while (right < size)
        {
            sum += nums[right];
            right++;
            while (sum >= target)
            {
                minlength = min(minlength, right - left - 1);
                left++;
                sum -= nums[left];
            }
        }
        if (left == -1 && sum < target) return 0;
        return minlength;
    }
};
int main()
{
    return 0;
}