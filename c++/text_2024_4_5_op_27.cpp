#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> PrevSum(n);
        auto PostSum = PrevSum;
        for (int i = 1;i < n;i++)PrevSum[i] = nums[i - 1] + PrevSum[i - 1];
        for (int i = n - 2;i >= 0;i--)PostSum[i] = nums[i + 1] + PostSum[i + 1];
        for (int i = 0;i < n;i++)
            if (PostSum[i] == PrevSum[i])return i;
        return -1;
    }
};
int main()
{
	return 0;
}