#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int Merger(vector<int>& record, int left, int right) {
        if (left >= right)return 0;
        int Sum = 0;
        int mid = left + (right - left) / 2, lbegin = left, rbegin = mid + 1;
        int sz = right - left + 1;
        Sum += Merger(record, left, mid);
        Sum += Merger(record, mid + 1, right);
        vector<int> temp;
        while (lbegin <= mid && rbegin <= right) {
            if (record[lbegin] > record[rbegin]) {
                Sum = Sum + right - rbegin + 1;
                temp.push_back(record[lbegin++]);
            }
            else temp.push_back(record[rbegin++]);
        }
        if (lbegin <= mid)
            while (lbegin <= mid)temp.push_back(record[lbegin++]);
        while (rbegin <= right)temp.push_back(record[rbegin++]);
        for (int i = 0;i < sz;i++)record[left + i] = temp[i];
        return Sum;
    }
    int reversePairs(vector<int>& record) {
        return Merger(record, 0, record.size() - 1);
    }
};
int main() {
    Solution s;
    vector<int> nums{ 7,5,6,4 };
    s.reversePairs(nums);
	return 0;
}