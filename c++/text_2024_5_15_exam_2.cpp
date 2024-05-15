#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int main() {
    int n = 0, m = 0;
    bool flag = false;
    cin >> n >> m;
    vector<vector<char>> chs(n + 1, vector<char>(m + 1));
    //起始点，终点

    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    char ch;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> chs[i][j];
        }
    }
    int lenth = 0;
    queue<pair<int, int>> q;
    q.push({ x1,y1 });
    chs[x1][y1] = '*';
    while (q.size()) {
        lenth++;
        int sz = q.size();
        while (sz--) {
            int a = q.front().first, b = q.front().second;
            q.pop();
            for (int i = 0;i < 4;i++) {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 1 && x <= n && y >= 1 && y <= m && chs[x][y] == '.') {
                    q.push({ x,y });
                    chs[x][y] = '*';
                    if (x == x2 && y == y2) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag)break;
        }
        if (flag)break;
    }
    if (flag)cout << lenth;
    else cout << -1;

    return 0;
}
