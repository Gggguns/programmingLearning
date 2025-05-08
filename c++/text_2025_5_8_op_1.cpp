#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            int sum = 0;
            for (auto e : nums)
            {
                if ((e >> i) & 1)sum++;
            }
            if (sum % 3)ret |= (1 << i);
        }
        return ret;
    }
};
int main()
{
    return 0;
}