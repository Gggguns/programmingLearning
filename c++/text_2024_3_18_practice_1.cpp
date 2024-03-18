#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class NumArray {
public:
    NumArray(vector<int>& nums) :_v(nums) {
    }

    int sumRange(int left, int right) {
        int RetSum = 0;
        for (int i = left;i <= right;i++)
        {
            RetSum += _v[i];
        }
        return RetSum;
    }
    vector<int> _v;
};
int main()
{
    return 0;
}