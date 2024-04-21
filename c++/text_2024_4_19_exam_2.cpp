#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:

    int dx[4] = { 0,0,1,-1 };
    int dy[4] = { 1,-1,0,0 };
    int rotApple(vector<vector<int> >& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++) {
                if (grid[i][j] == 1)count++;
                else if (grid[i][j] == 2) {
                    q.push({ i,j });
                    vis[i][j] = true;
                }
            }
        //广度优先遍历
        int level = 0;
        int sz = 0;
        while (q.size()) {
            sz = q.size();
            for (int i = 0;i < sz;i++) {
                int a = q.front().first;
                int b = q.front().second;
                q.pop();
                for (int k = 0;k < 4;k++) {
                    int x = a + dx[k];
                    int y = b + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y]) {
                        if (grid[x][y] == 1) {
                            q.push({ x,y });
                            count--;
                        }
                        vis[x][y] = true;
                    }
                }
            }
            level++;
        }
        if (count)return -1;
        else return level - 1;
    }
};
int main()
{
	return 0;
}