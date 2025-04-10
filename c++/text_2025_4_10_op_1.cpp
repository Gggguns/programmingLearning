#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int size = nums.size();
        int left = -1, right = 0;
        int zeroSize = 0, oneSize = 0;
        while (right < size)
        {
            // Slide into windown
            if (nums[right] == 0) zeroSize++;
            right++;
            if (k < zeroSize)
            {
                oneSize = max(oneSize, right - left - 2);
                // Slide out window
                while (k < zeroSize)
                {
                    left++;
                    if (nums[left] == 0) zeroSize--;
                }
            }
        }
        oneSize = max(oneSize, right - left - 1);
        return oneSize;
    }
};
int main()
{
	return 0;
}