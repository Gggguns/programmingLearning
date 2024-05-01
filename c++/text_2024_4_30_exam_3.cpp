#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    unordered_map<int, long long> hash;
    int num = 0, Max = 0;
    for (int i = 0;i < n;i++) {
        cin >> num;
        Max = max(Max, num);
        hash[num] += num;
    }
    vector<long long> f(Max + 1);
    auto g = f;
    f[0] = hash[0];
    for (int i = 1;i <= Max;i++) {
        f[i] = g[i - 1] + hash[i];
        g[i] = max(g[i - 1], f[i - 1]);
    }
    cout << max(g[Max], f[Max]);
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")