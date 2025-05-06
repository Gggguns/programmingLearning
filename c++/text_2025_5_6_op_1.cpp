#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long size = nums.size();
        long  result = 0;
        for (long i = 0; i <= size; i++)result ^= i;
        for (auto e : nums)result ^= e;
        return result;
    }
};
int main()
{
    return 0;
}