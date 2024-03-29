#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for (int i = 0;i < n - 3;) {
            for (int j = i + 1;j < n - 2;)
            {
                long long Res = (long long)target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long Sum = nums[left] + nums[right];
                    if (Sum == Res)
                    {
                        v.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        left++;
                        while (left < right && nums[left] == nums[left - 1])left++;
                        right--;
                        while (left < right && nums[right] == nums[right + 1])right--;
                    }
                    else if (Sum > Res)
                    {
                        if (nums[left] > nums[right])left++;
                        else right--;
                    }
                    else {
                        if (nums[left] > nums[right])right--;
                        else left++;
                    }
                }
                j++;
                while (j < n - 2 && nums[j] == nums[j - 1])j++;
            }
            i++;
            while (i < n - 3 && nums[i] == nums[i - 1])i++;
        }
        return v;
    }
};
int main()
{
    vector<int> nums{ 1,0,-1,0,-2,2 };
    Solution s;
    s.fourSum(nums,0);
    return 0;
}