#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> v(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    int left = 1, right = 1;
    for (int i = 0;i < q;i++) {
        cin >> left >> right;
        cout << v[right] - v[left - 1] << endl;
    }
    return 0;
}
