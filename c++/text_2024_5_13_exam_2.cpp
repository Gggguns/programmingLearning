#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

    bool hostschedule(vector<vector<int> >& schedule) {
        sort(schedule.begin(), schedule.end());
        int begin = schedule[0][0], end = schedule[0][1];
        size_t sz = schedule.size();
        for (size_t i = 1;i < sz;i++) {
            if (schedule[i][0] < end)return false;
            begin = schedule[i][0];
            end = schedule[i][1];
        }
        return true;
    }
};
int main() {
	return 0;
}