#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int remax = -1;
        while (left < right)
        {
            int minHeight = min(height[left], height[right]);
            int width = right - left;
            remax = max(remax, width * minHeight);
            if (height[left] < height[right])left++;
            else right--;
        }
        return remax;
    }
};
int main()
{
	return 0;
}