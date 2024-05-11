#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<long long>> vv(n + 1, vector<long long>(n + 1));
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> vv[i][j];
            vv[i][j] = vv[i][j] + vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1];
        }
    }
    long long Max = -0x3fffff;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            for (int h = i;h <= n;h++) {
                for (int k = j;k <= n;k++) {
                    long long Res = vv[h][k] - vv[i - 1][k] - vv[h][j - 1] + vv[i - 1][j - 1];
                    Max = max(Max, Res);
                }
            }
        }
    }
    cout << Max;
    return 0;
}
// 64 位输出请用 printf("%lld")// 64 位输出请用 printf("%lld")