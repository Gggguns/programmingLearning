#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        size_t n = nums.size();
        int left = -1, right = 0;
        int Len = -1, Sum = 0;
        while (left < right && right < n)
        {
            if (Sum <= k) {
                if (nums[right] == 0)Sum++;
                right++;
            }
            else {
                Len = max(Len, right - left - 2);
                while (Sum > k) {
                    left++;
                    if (nums[left] == 0)Sum--;
                }
            }
        }
        if (Sum > k)Len = max(Len, right - left - 2);
        else Len = max(Len, right - left - 1);
        if (Len < 0)return 0;
        else return Len;
    }
};
int main()
{
	return 0;
}