#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int left = -1, right = 0, cur = 0;
        for (cur = 0; cur < size; cur++)
        {
            if (nums[cur] == 0)
            {
                left++;
                swap(nums[left + 1], nums[cur]);
            }
            if (nums[cur] == 1)
            {
                right++;
                swap(nums[right], nums[cur]);
            }
        }
    }
};
int main()
{
    return 0;
}