#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<long long, int> Hash;
        int sz = nums.size();
        int a = 0, b = 0;
        for (int i = 0;i < sz;i++) {
            if (Hash.count(target - nums[i])) {
                a = Hash[target - nums[i]];
                b = i;
                break;
            }
            else Hash[nums[i]] = i;
        }
        return { a,b };
    }
};
int main() {
    Solution s;
    vector<int> nums{ 2,7,11,15 };
    s.twoSum(nums, 9);
	return 0;
}