#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
class Solution {
public:
    int n = 0, m = 0;
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { -1,1,0,0 };
    bool vis[201][201];
    void dfs(vector<vector<char> >& grid, int a, int b) {
        if (vis[a][b])return;
        vis[a][b] = true;
        for (int k = 0;k < 4;k++) {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == '1') {
                dfs(grid, x, y);
            }
        }
    }
    int solve(vector<vector<char> >& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        memset(vis, false, sizeof(vis));
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
int main()
{
	return 0;
}