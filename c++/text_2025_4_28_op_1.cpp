#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n = 0, m = 0, q = 0;
    cin >> n >> m >> q;
    vector<vector<long long>> vv(n + 1, vector<long long>(m + 1));
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            cin >> vv[i][j];
            vv[i][j] = vv[i][j] + vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1];
        }
    }
    while (q--)
    {
        long long a = 0, b = 0, c = 0, d = 0;
        cin >> a >> b >> c >> d;
        long long result = vv[c][d] - vv[a - 1][d] - vv[c][b - 1] + vv[a - 1][b - 1];
        cout << result;
        if (q > 0)cout << endl;
    }
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")