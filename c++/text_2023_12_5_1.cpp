#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int w = 0, h = 0;
    cin >> w >> h;
    vector<vector<int>> vv;
    vv.resize(w);
    for (auto& e : vv)
    {
        e.resize(h, 1);
    }
    int res = 0;
    int i = 0, j = 0;
    for (i = 0;i < w;i++)
    {
        for (j = 0;j < h;j++)
        {
            if (vv[i][j] == 1)
            {
                res++;
                if (i + 2 < w)
                {
                    vv[i + 2][j] = 0;
                }

                if (j + 2 < h)
                {
                    vv[i][j + 2] = 0;
                }
            }
        }
    }
    cout << res;
    return 0;
}