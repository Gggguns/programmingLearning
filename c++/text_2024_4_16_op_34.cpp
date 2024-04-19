#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Ret = 0;
        int n = nums.size();
        for (auto e : nums)Ret ^= e;
        for (int i = 0;i <= n;i++)Ret ^= i;
        return Ret;
    }
};
int main()
{
	return 0;
}