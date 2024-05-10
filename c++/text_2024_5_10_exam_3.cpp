#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    bool vis[201] = { 0 };
    void bfs(vector<vector<int> >& m, int i) {
        if (vis[i])return;
        queue<int> Q;
        vis[i] = true;
        Q.push(i);
        while (Q.size()) {
            int city = Q.front();
            Q.pop();
            int sz = m[city].size();
            for (int j = 0;j < sz;j++) {
                if (m[city][j] == 1 && vis[j] == false) {
                    vis[j] = true;
                    Q.push(j);
                }
            }
        }
    }
    int citys(vector<vector<int> >& m) {
        int Ret = 0;
        int n = m.size();
        for (int i = 0;i < n;i++) {
            if (!vis[i]) {
                Ret++;
                bfs(m, i);
            }
        }
        return Ret;
    }
};
int main() {
    Solution s;
    vector<vector<int>> m{ {1,1,0},{1,1,0},{0,0,1} };
    cout << s.citys(m);
	return 0;
}