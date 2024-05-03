#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int Sum = 0, Ret = 0;
        for (int i = 0;i < 32;i++) {
            Sum = 0;
            for (auto e : nums) {
                Sum += ((e >> i) & 1);
            }
            Sum %= 3;
            Ret |= (Sum << i);
        }
        return Ret;
    }
};
int main(){
    Solution s;
    vector<int> nums{ 0,1,0,1,0,1,99};
    s.singleNumber(nums);
	return 0;
}