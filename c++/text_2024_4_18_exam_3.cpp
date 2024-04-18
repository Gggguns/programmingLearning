#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> vv(n, vector<int>(n));
    vv[0][0] = 1;
    for (int i = 1;i < n;i++) {
        vv[i][0] = 1;
        vv[i][i] = 1;
        for (int j = 1;j < i;j++)vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
    }
    for (int i = 0;i < n;i++) {
        for (int j = 0;j <= i;j++) {
            int num = vv[i][j];
            printf("%5d", num);
        }
        if (i < n - 1)cout << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")