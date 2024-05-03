#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int Ret = 0;
        bool injury = false;
        int cur = 0, prev = 0;
        for (auto e : timeSeries) {
            cur = e;
            if (injury)Ret += (cur - prev > duration ? duration : cur - prev);
            injury = true;
            prev = cur;
        }
        Ret += duration;
        return Ret;
    }
};
int main() {
	return 0;
}