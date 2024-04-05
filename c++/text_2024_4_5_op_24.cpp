#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        long long mid = 0, left = -1, right = records.size() - 1;
        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (mid < records[mid])right = mid - 1;
            else left = mid;
        }
        return left + 1;
    }
};
int main()
{
    return 0;
}