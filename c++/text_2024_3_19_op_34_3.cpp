#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int Ret = 0;
        for (int i = 0;i < 32;i++)
            if ((n >> i) & 1)Ret++;
        return Ret;
    }
};
int main()
{
    return 0;
}