#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int Third = nums.size() - 1;
        int Seconed = Third - 1, One = 0;
        int Sum = 0;
        while (Third > 1)
        {
            Seconed = Third - 1;
            One = 0;
            while (One < Seconed)
            {
                if (nums[One] + nums[Seconed] > nums[Third])
                {
                    Sum = Sum + Seconed - One;
                    Seconed--;
                }
                else One++;
            }
            Third--;
        }
        return Sum;
    }
};
int main()
{
    Solution s;
    vector<int> nums{ 2,2,3,4 };
    s.triangleNumber(nums);
	return 0;
}