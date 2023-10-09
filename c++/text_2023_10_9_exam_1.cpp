#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    while (N > v[v.size() - 1])
    {
        v.push_back(v[v.size() - 1] + v[v.size() - 2]);
    }
    int size1 = v[v.size() - 1] - N;
    int size2 = N - v[v.size() - 2];
    if (size1 > size2)
    {
        cout << size2;
    }
    else
    {
        cout << size1;
    }
    return 0;
}