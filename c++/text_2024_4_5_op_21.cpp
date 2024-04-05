#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        long long left = 0, right = arr.size() - 1, mid = 0;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1])right = mid;
            else left = mid + 1;
        }
        return right;
    }
};
int main()
{
    return 0;
}