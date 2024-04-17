#define _CRT_SECURE_NO_WARNINGS
#include <climits>
#include <iostream>
#include<vector>
using namespace std;

int main() {
    long long n = 0, x = 0, left = -1, right = 0, Sum = 0, head = 0xfffffff, ResL = -1, ResR = 0;
    cin >> n >> x;
    ResR = n;
    vector<int> v(n);
    //ÊäÈën¸öÊý
    for (auto& e : v) {
        cin >> e;
    }
    while (right < n) {
        Sum += v[right++];
        while (Sum >= x) {
            long long len = right - left;
            long long Rlen = ResR - ResL;
            if (len < Rlen) {
                ResR = right;
                ResL = left;
                head = v[left + 1];
            }
            Sum -= v[++left];
        }
    }
    cout << ResL + 2 << ' ' << ResR;
    return 0;
}
