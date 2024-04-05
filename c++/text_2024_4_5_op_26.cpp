#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n = 0, m = 0, q = 0;
    cin >> n >> m >> q;
    vector<vector<long long>> vv(n + 1, vector<long long>(m + 1));
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            cin >> vv[i][j];
            vv[i][j] += vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1];
        }
    int x1 = 1, x2 = 1, y1 = 1, y2 = 1;
    for (int i = 0;i < q;i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        long long Res = vv[x2][y2] - vv[x1 - 1][y2] - vv[x2][y1 - 1] + vv[x1 - 1][y1 - 1];
        cout << Res << endl;
    }
    return 0;
}