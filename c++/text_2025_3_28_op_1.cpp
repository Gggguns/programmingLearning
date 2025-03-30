#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int cur = 0, dest = -1;
        while (dest < size)
        {
            if (arr[cur])dest++;
            else dest += 2;
            if (dest >= size - 1)break;
            cur++;
        }
        if (dest == size)
        {
            arr[--dest] = 0;
            cur--; dest--;
        }
        while (cur != dest)
        {
            arr[dest--] = arr[cur];
            if (!arr[cur])arr[dest--] = arr[cur];
            cur--;
        }
    }
};
int main()
{
    vector<int> nums;
    nums = { 0, 0, 0, 0, 9, 1, 0, 0, 1, 1, 0, 5, 1, 6, 0, 0, 2, 7, 0, 3, 3, 2, 0, 0, 7, 3, 3, 0, 5, 7, 0, 8, 0, 0, 0, 5, 0, 0, 0, 3, 5, 1, 0, 0, 8, 0, 0 };
    Solution s;
    s.duplicateZeros(nums);
	cout << "hello";
	return 0;
}