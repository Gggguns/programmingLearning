#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0, m = 0, x = 0, y = 0;
    cin >> n >> m >> x >> y;
    n += 2;m += 2;
    vector<vector<long long>> board(n, vector<long long>(m));
    //ÂíµÄÂä½Åµã
    int dx[9] = { 0,1,-1,1,-1,2,-2,2,-2 };
    int dy[9] = { 0,2, 2,-2,-2,1,1,-1,-1 };
    for (int i = 0;i < 9;i++) {
        int a = x + dx[i] + 1;
        int b = y + dy[i] + 1;
        if (a >= 1 && a < n && b >= 1 && b < m)board[a][b] = -1;
    }
    board[0][1] = 1;
    for (int i = 1;i < n;i++) {
        for (int j = 1;j < m;j++) {
            if (board[i][j] == -1) {
                board[i][j] = 0;
                continue;
            }
            board[i][j] = board[i - 1][j] + board[i][j - 1];
        }
    }
    cout << board[n - 1][m - 1];
    return 0;
}
