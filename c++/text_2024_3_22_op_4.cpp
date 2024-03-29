#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int Ret = min(left, right) * (right - left);
        while (left < right)
        {
            int Res = min(height[left], height[right]) * (right - left);
            Ret = max(Ret, Res);
            if (height[left] < height[right])left++;
            else right--;
        }
        return Ret;
    }
};
int main()
{
	return 0;
}