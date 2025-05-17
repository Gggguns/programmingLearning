#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        srand(time(nullptr));
        qsort(stock, 0, stock.size() - 1);
        vector<int> ret;
        for (int i = 0; i < cnt; i++)ret.push_back(stock[i]);
        return ret;
    }
    void qsort(vector<int>& nums, int left, int right)
    {
        if (left > right)return;
        int cur = left;
        int key = nums[rand() % (right - left + 1) + left];
        int start = left, end = right;
        while (cur <= right)
        {
            if (nums[cur] > key)swap(nums[right--], nums[cur]);
            else if (nums[cur] < key)swap(nums[left++], nums[cur++]);
            else cur++;
        }
        qsort(nums, start, left - 1);
        qsort(nums, right + 1, end);
        return;
    }
};
int main()
{
    return 0;
}