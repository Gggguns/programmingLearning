#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int temp = 0, sz = nums.size();
        for (int i = 0;i < sz;i++)temp ^= nums[i];
        for (int i = 1;i <= sz + 2;i++)temp ^= i;
        int lowbit = temp & (~temp + 1);
        int a = 0, b = 0;
        for (int i = 0;i < sz;i++) {
            if (lowbit & nums[i])a ^= nums[i];
            else b ^= nums[i];
        }
        for (int i = 1;i <= sz + 2;i++) {
            if (lowbit & i)a ^= i;
            else b ^= i;
        }
        return { a,b };
    }
};
int main() {
	return 0;
}