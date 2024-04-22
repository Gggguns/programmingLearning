#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    while (n--) {
        int sz = 6;
        vector<long long> v(sz);
        for (auto& e : v)cin >> e;
        sort(v.begin(), v.end());
        if (v[0] + v[1] > v[2] && v[3] + v[4] > v[5] ||
            v[0] + v[2] > v[3] && v[1] + v[4] > v[5] ||
            v[0] + v[3] > v[4] && v[1] + v[2] > v[5] ||
            v[0] + v[4] > v[5] && v[1] + v[2] > v[3])
            cout << "Yes\n";
        else cout << "No\n";
    }
}