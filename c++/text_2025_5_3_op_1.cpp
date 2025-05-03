#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<long long, long long> hash;
        hash[0] = -1;
        long long ret = 0, size = nums.size();
        long long sum = 0;
        for (long long i = 0; i < size; i++)
        {
            sum += (nums[i] == 0 ? -1 : 1);
            if (hash.count(sum))ret = max(ret, i - hash[sum]);
            else hash[sum] = i;
        }
        return ret;
    }
};
int main()
{
    return 0;
}