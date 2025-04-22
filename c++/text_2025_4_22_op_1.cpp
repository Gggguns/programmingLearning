#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int mid = (left + right) / 2;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (arr[mid + 1] >= arr[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};
int main()
{
    return 0;
}