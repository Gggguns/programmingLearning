#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int Index = 0;
        Index = nums.size() - 2;
        long long Max = 0, Sum = nums[nums.size() - 1];
        while (Index >= 0)
        {
            if (Sum >= nums[Index])
            {
                Sum += nums[Index];
                Index--;
            }
            else
            {
                if (Sum > Max)Max = Sum;
                Sum = nums[Index];
                Index--;
            }
        }
        if (Sum > Max)Max = Sum;
        return Sum;
    }
};
int main()
{
	return 0;
}