#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
    vector<double> v(3);
    while (cin >> v[0] >> v[1] >> v[2])
    {
        sort(v.begin(), v.end());
        if (v[0] + v[1] > v[2])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}