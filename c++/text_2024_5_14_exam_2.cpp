#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    long long n = 0;
    cin >> n;
    vector<long long> nums(n);
    for (auto& e : nums)cin >> e;
    vector<long long> f(n);
    vector<long long> g(n);
    f[0] = nums[0];
    for (long long i = 1;i < n;i++) {
        f[i] = g[i - 1] + nums[i];
        g[i] = max(g[i - 1], f[i - 1]);
    }
    cout << max(g[n - 1], f[n - 1]);
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")