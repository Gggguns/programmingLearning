#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n = 0, q = 0;
    cin >> n >> q;
    vector<long long> pSum(n + 1);
    for (long long i = 1;i <= n; i++)
    {
        cin >> pSum[i];
        pSum[i] += pSum[i - 1];
    }
    long long left = 1, right = 1;
    while (q--)
    {
        cin >> left >> right;
        cout << pSum[right] - pSum[left - 1];
        if (q > 0)cout << endl;
    }
}