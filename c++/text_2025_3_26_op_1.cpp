#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = -1, dest = -1;
        int size = nums.size();
        while (cur + 1 < size)
        {
            cur++;
            if (nums[cur] == 0) continue;
            else swap(nums[cur], nums[++dest]);
        }
    }
};
int main()
{
	return 0;
}