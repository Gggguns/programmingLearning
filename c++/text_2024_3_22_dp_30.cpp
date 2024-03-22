#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> len(n, 1);
        int Ret = 1;
        for (int i = 1;i < n;i++)
        {
            for (int j = 0;j < i;j++)
            {
                if (pairs[j][1] < pairs[i][0])len[i] = max(len[i], len[j] + 1);
            }
            if (Ret < len[i])Ret = len[i];
        }
        return Ret;
    }
};


int main()
{
    vector<vector<int>> pairs{ {-3,9}, {-5,0},{6,7},{2,6},{-9,-3},{-5,-3},{-7,7},{-2,10},{7,8},{-1,10} };
    Solution s;
    s.findLongestChain(pairs);
	return 0;
}