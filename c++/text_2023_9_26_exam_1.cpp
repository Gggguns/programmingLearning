#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    int i = 0;
    int result = 0;
    for (i = 0;i < 4;i++)
    {
        cin >> result;
        v.push_back(result);
    }
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    for (i = 0;i <= 30;i++)
    {
        A = i;
        B = A - v[0];
        C = B - v[1];
        if (A + B == v[2] && B + C == v[3])
        {
            cout << A << ' ' << B << ' ' << C;
            break;
        }
    }
    if (i > 30)
    {
        cout << "No";
    }
    return 0;
}