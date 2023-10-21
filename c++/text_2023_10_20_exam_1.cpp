#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int cow = 0, row = 0;
    cin >> cow;
    /*row = cow * 2 - 1;
    int i = 0;
    vector<long> v1, v2;
    v1.resize(row, 0);
    v2.resize(row, 0);
    for (i = 0;i < cow;i++)
    {
        int j = 0;
        for (j = 0;j < i * 2;j++)
        {
            if (j == 0)
            {
                v2[j] = 1;
                continue;
            }
            v2[j] = v1[j] + v1[j - 1];
            if (j - 2 >= 0)
            {
                v2[j] += v1[j - 2];
            }
        }
        v2[j] = 1;
        v1.swap(v2);
    }*/
    //    for(auto e:v1)
    //    {

    //         cout<<e<<' ';

    //    }
       //查找第一次出现的偶数
   /* for (i = 1;i < v1.size();i++)
    {
        if (v1[i] % 2 == 0)
        {
            cout << (i + 1);
            break;
        }
    }
    if (v1.size() == i)
    {
        cout << -1;
    }*/
    if (cow < 3)
    {
        cout << -1;
    }
    else if ((cow - 2) % 4 == 2)
    {
        cout << 3;
    }
    else if ((cow - 2) % 4 == 0)
    {
        cout << 4;
    }
    else
    {
        cout << 2;
    }
    return 0;
}