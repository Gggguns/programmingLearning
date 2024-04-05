#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int Ret = 0, n = nums.size();
        unordered_map<long long, int> hash;
        long long Sum = 0;
        for (int i = 0;i < n;i++) {
            Sum += nums[i];
            if (hash.count(Sum - k))Ret += hash[Sum - k];
            if (Sum == k)Ret++;
            hash[Sum]++;
        }
        return Ret;
    }
};
int main()
{
	return 0;
}