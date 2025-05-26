#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int, int> hash;
        for (int i = 0; i < size; i++)
        {
            int res = target - nums[i];
            if (hash.count(res))return { hash[res], i };
            hash[nums[i]] = i;
        }
        return { 0, 0 };
    }
};
int main()
{
	return 0;
}