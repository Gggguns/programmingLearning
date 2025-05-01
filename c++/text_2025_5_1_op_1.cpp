#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<long long, int> hash;
        hash[0] = 1;
        int count = 0;
        for (auto e : nums)
        {
            sum += e;
            count += hash[sum - k];
            hash[sum]++;
        }
        return count;
    }
};
int main()
{
    return 0;
}