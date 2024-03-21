#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int Cur = 0, Dest = -1;
        int n = arr.size();
        while (Dest != n - 1 && Dest < n)
        {
            if (arr[Cur++])Dest++;
            else Dest += 2;
        }
        Cur--;
        if (Dest > n - 1)
        {
            Dest--;
            arr[Dest--] = arr[Cur--];
        }
        while (Cur >= 0)
        {
            arr[Dest--] = arr[Cur];
            if (arr[Cur] == 0)arr[Dest--] = arr[Cur];
            Cur--;
        }
    }
};
int main()
{
    vector<int> nums(3);
    for (auto& e : nums)cin >> e;
    Solution s;
    s.duplicateZeros(nums);
    return 0;
}