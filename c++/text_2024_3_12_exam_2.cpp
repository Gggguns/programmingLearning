#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {

    int Size = (int)1e6;
    int MOL = (int)1e6;
    vector<int> v(Size + 1);
    v[0] = 1;v[1] = 1;
    for (int i = 2;i < Size + 1;i++)
    {
        v[i] = (v[i - 1] + v[i - 2]) % MOL;
    }
    long n;
    while (cin >> n)
    {
        if (n > 25)
        {
            printf("%06d\n", v[n]);
        }
        else
        {
            printf("%d\n", v[n]);
        }


    }
    return 0;
}
