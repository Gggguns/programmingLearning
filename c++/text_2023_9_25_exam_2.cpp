#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define N 7

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int>& v)
    {
        sort(v.begin(), v.end());
        int num = v[0];
        int size = 0;
        for (auto e : v)
        {
            if (num == e)
            {
                size++;
            }
            else
            {
                if (size > v.size() / 2)
                {
                    return num;
                }
                num = e;
                size++;
            }
        }
        if (size > v.size() / 2)
        {
            return num;
        }
        else
        {
            return 0;
        }
    }
};
int main()
{
    Solution S;
    vector<int> v;
    int e = 0;
    for (int i = 0;i < N;i++)
    {
        cin >> e;
        v.push_back(e);
    }
    int x=0;
    cout<<S.MoreThanHalfNum_Solution(v);
	return 0;
}