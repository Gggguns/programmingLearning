#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ret = 0, size = timeSeries.size(), prevtime = -1;
        for (int i = 0; i < size; i++)
        {
            if (prevtime != -1)ret += min(duration, timeSeries[i] - prevtime);
            prevtime = timeSeries[i];
        }
        ret += duration;
        return ret;
    }
};
int main()
{
    return 0;
}