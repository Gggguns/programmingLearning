#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int takeAttendance(vector<int>& records) {
        int left = 0, right = records.size() - 1;
        int mid = (left + right) / 2;
        while (left < right)
        {
            mid = (left + right) / 2 + 1;
            if (records[mid] == mid) left = mid;
            else right = mid - 1;
        }
        if (records[left] == left)return left + 1;
        else return left;
    }
};
int main()
{
	return 0;
}