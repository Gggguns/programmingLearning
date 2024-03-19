#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Ret = 0;
        for (auto e : nums)
            Ret ^= e;
        return Ret;
    }
};
int main()
{
    return 0;
}