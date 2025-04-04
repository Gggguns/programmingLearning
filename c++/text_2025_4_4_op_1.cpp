#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                for (int h = j + 1; h < size; h++)
                {
                    // valid
                    if (nums[i] + nums[j] > nums[h])
                    {
                        sum++;
                    }
                    else break;
                }
            }
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1,2,3,4,5,6 };
    s.triangleNumber(nums);
    return 0;
}