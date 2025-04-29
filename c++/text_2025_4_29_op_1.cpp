#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long size = nums.size();
        vector<long long> prefixsum(size);
        vector<long long> postfixsum(size);
        for (long long i = size - 2; i >= 0; i--)
        {
            postfixsum[i] = postfixsum[i + 1] + nums[i + 1];

        }
        cout << endl;
        for (long long i = 1; i < size; i++)
        {
            prefixsum[i] = nums[i - 1] + prefixsum[i - 1];
        }
        for (long long i = 0; i < size; i++)
        {
            if (prefixsum[i] == postfixsum[i]) return i;
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 2,1,-1 };
    s.pivotIndex(nums);
    return 0;
}