#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//    int minOperations(vector<int>& nums, int x) {
//        int n = nums.size();
//        long long Sum = 0;
//        int Ret = INT_MAX;
//        for (int i = 0;i < n;i++) {
//            Sum += nums[i];
//        }
//        long long Res = Sum - x;
//        Sum = 0;
//        int left = -1, right = 0;
//        while (left < right && right < n) {
//            if (Sum < Res)Sum += nums[right++];
//            else if (Sum == Res) {
//                Ret = min(Ret, n - right + left + 1);
//                Sum += nums[right++];
//                Sum -= nums[++left];
//            }
//            else Sum -= nums[++left];
//        }
//        while (Sum > Res && left >= -1 && left < right)Sum -= nums[++left];
//        if (Sum == Res)Ret = min(n - right + left + 1, Ret);
//        if (Ret > n)return -1;
//        else return Ret;
//    }
//};
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long Sum = 0;
        int Ret = -1;
        for (int i = 0;i < n;i++) {
            Sum += nums[i];
        }
        if (Sum < x) return -1;
        long long Res = Sum - x;
        Sum = 0;
        int left = -1, right = 0;
        while (left < right && right < n) {
            Sum += nums[right++];
            while (Sum > Res) {
                left++;
                Sum -= nums[left];
            }
            if (Sum == Res)Ret = max(Ret, right - left - 1);
        }
        if (Ret == -1)return -1;
        else return nums.size() - Ret;
    }
};
int main()
{
    Solution s;
    vector<int> nums{ 1,1,99 };
    cout<<s.minOperations(nums,2);
	return 0;
}