#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    int i = 0;
    vector<string> v;
    for (i = 0;i < N;i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    bool dicjuage = true;
    for (i = 0;i < v.size() - 1;i++)
    {
        if (v[i] > v[i + 1])
        {
            dicjuage = false;
            break;
        }
    }
    bool lenjuage = true;
    for (i = 0;i < v.size() - 1;i++)
    {
        if (v[i].size() > v[i + 1].size())
        {
            lenjuage = false;
            break;
        }
    }
    if (dicjuage && lenjuage)
    {
        cout << "both";
    }
    else if (dicjuage && lenjuage == false)
    {
        cout << "lexicographically";
    }
    else if (dicjuage == false && lenjuage)
    {
        cout << "lengths";
    }
    else
    {
        cout << "none";
    }
    return 0;
}