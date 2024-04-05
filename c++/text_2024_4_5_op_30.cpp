#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int Ret = 0, n = nums.size();
        long long Sum = 0;
        unordered_map<int, int> hash;
        for (int i = 0;i < n;i++) {
            Sum += nums[i];
            int Res = ((Sum) % k + k) % k;
            if (hash.count(Res))Ret += hash[Res];
            if (Sum % k == 0)Ret++;
            hash[Res]++;
        }
        return Ret;
    }
};
int main()
{
    Solution s;
    vector<int> nums{ -1,-9,-4,0 };
    s.subarraysDivByK(nums, 9);
	return 0;
}