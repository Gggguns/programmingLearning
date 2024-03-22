#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1), count(n, 1);
        for (int i = 1;i < n;i++)
        {
            for (int j = 0;j < i;j++)
            {
                if (nums[i] > nums[j])
                {
                    if (len[i] < len[j] + 1)
                    {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    }
                    else if (len[i] == len[j] + 1)
                    {
                        count[i] += count[j];
                    }
                }
            }
        }
        int Ret = count[0], Max = len[0];
        for (int i = 1;i < n;i++)
        {
            if (len[i] == Max)Ret += count[i];
            if (Max < len[i])
            {
                Ret = count[i];
                Max = len[i];
            }
        }
        return Ret;
    }
};
int main()
{
    return 0;
}