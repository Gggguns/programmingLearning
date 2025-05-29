#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (hash.count(nums[i]))
            {
                if (i - hash[nums[i]] <= k)return true;
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};
int main()
{
	return 0;
}