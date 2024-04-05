#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)return 0;
        long long left = 0, right = x, mid = 0;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (mid * mid > x)right = mid - 1;
            else left = mid;
        }
        return left;
    }
};
int main()
{
	return 0;
}