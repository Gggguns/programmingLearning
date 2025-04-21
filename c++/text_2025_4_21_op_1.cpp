#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int mid = (left + right) / 2;
        if (x == 0) return 0;
        while (left < right)
        {
            mid = (left + right) / 2 + 1;
            if ((long)mid * mid <= x) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};
int main()
{
    Solution s;
    s.mySqrt(0);
    return 0;
}