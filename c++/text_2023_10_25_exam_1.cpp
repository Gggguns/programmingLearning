#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int GroupNum = 0;
    cin >> GroupNum;
    int i = 0;
    for (i = 0;i < GroupNum;i++)
    {
        int n = 0, k = 0;
        cin >> n >> k;
        vector<int> v1;
        v1.resize(2 * n);
        int j = 0;
        for (j = 0;j < 2 * n;j++)
        {
            cin >> v1[j];
        }
        vector<int> v2;
        while (k--)
        {
            for (j = 2 * n - 1;j >= n;j--)
            {
                v2.push_back(v1[j]);
                v2.push_back(v1[j - n]);
            }
            reverse(v2.begin(), v2.end());
            v1 = v2;
            v2.clear();
        }
        for (auto e : v1)
        {
            cout << e << ' ';
        }
        if (i < GroupNum - 1)
            cout << endl;
    }

    return 0;
}