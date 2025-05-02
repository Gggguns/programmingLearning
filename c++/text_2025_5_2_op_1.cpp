#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<long long, long long> hash;
        hash[0] = 1;
        long long ret = 0;
        long long sum = 0;
        for (auto e : nums)
        {
            sum += e;
            long long key = (sum % k + k) % k;
            ret += hash[key];
            hash[key]++;
        }
        return ret;
    }
};
int main()
{
    return 0;
}