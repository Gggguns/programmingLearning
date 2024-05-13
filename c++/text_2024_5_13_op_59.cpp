#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<long long, int> Hash;
        int sz = nums.size();
        for (int i = 0;i < sz;i++) {
            if (Hash.count(nums[i])) {
                if (i - Hash[nums[i]] <= k)return true;
            }
            Hash[nums[i]] = i;
        }
        return false;
    }
};
int main() {
	return 0;
}