#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> preproduct(size, 1), sufproduct(size, 1);
        vector<int> ret(size);
        for (int i = 1; i < size; i++)
        {
            preproduct[i] = preproduct[i - 1] * nums[i - 1];
        }
        for (int i = size - 2; i >= 0; i--)
        {
            sufproduct[i] = sufproduct[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < size; i++)
        {
            ret[i] = preproduct[i] * sufproduct[i];
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> nums = { 1, 2, 3 };
    s.productExceptSelf(nums);
    return 0;
}