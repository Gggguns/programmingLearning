#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), Ret = 0;
        long long Sum = 0;
        unordered_map<int, int> hash;
        for (int i = 0;i < n;i++) {
            Sum += nums[i] == 0 ? -1 : 1;
            if (hash.count(Sum))Ret = max(Ret, i - hash[Sum]);
            else hash[Sum] = i;
            if (Sum == 0)Ret = max(Ret, i + 1);
        }
        return Ret;
    }
};
int main()
{
	return 0;
}