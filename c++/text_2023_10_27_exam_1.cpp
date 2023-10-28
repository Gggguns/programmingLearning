#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Gift {
public:
    int getValue(vector<int> gifts, int n)
    {
        int Half = n / 2;
        int Num = gifts[0];
        int i = 0;
        int size = 0;
        sort(gifts.begin(), gifts.end());
        for (i = 1;i < gifts.size();i++)
        {
            Num = gifts[i - 1];
            if (gifts[i] == Num)
            {
                size++;
            }
            else
            {
                if (size + 1 > Half)
                {
                    return Num;
                }
            }
        }
        return 0;
    }
};
int main()
{
    vector<int> v;
    int n=0;
    int num = 0;
    while (cin >> num)
    {
        v.push_back(num);
    }
    n = v.back();
    v.pop_back();
    Gift g;
    g.getValue(v, n);
    return 0;
}