#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for (auto e : nums)temp ^= e;
        int diff = 0;
        while (true)
        {
            if (((temp >> diff) & 1) == 1)break;
            else diff++;
        }
        int a = 0, b = 0;
        for (auto e : nums)
        {
            if (((e >> diff) & 1) == 1)b ^= e;
            else a ^= e;
        }
        return { a,b };
    }
};
int main()
{
    return 0;
}