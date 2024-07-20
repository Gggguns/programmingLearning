#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    long long n, m, a, b, ret = 0;
    cin >> n >> m >> a >> b;
    for (long long x = 0;x <= min(n / 2, m);x++) {
        long long y = min(n - 2 * x, (m - x) / 2);
        ret = max(ret, x * a + y * b);
    }
    cout << ret;
    return 0;
}