#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int k = 0;
    while (cin >> k)
    {

        while (k--)
        {
            vector<vector<long long>> vv1(2, vector<long long>(2, 0));
            vv1[0][0] = vv1[1][0] = vv1[0][1] = 1;
            vv1[1][1] = 0;
            vector<vector<long long>> vv2(vv1);
            vector<vector<long long>> vv3(vv1);
            int time = 0;
            cin >> time;
            while (--time)
            {
                vv3[0][0] = (vv2[0][0] * vv1[0][0] + vv2[0][1] * vv1[1][0]) % 10000;
                vv3[0][1] = (vv2[0][0] * vv1[0][1] + vv2[0][1] * vv1[1][1]) % 10000;
                vv3[1][0] = (vv2[1][0] * vv1[0][0] + vv2[1][1] * vv1[1][0]) % 10000;
                vv3[1][1] = (vv2[1][0] * vv1[0][1] + vv2[1][1] * vv1[1][1]) % 10000;
                vv2.swap(vv3);
            }
            printf("%.4lld", vv2[0][0] % 10000);

        }
        cout << endl;
    }
}