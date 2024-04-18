#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
    typedef pair<int, int> PII;
    int dx[4] = { 0,0,-1,1 };
    int dy[4] = { 1,-1,0,0 };
    bool vis[101][101] = { 0 };
    int n = 0, m = 0;
public:

    bool dfs(vector<string>& board, string& word, int i, int j, int pos) {
        if (pos == word.size() - 1)return true;
        vis[i][j] = true;
        for (int h = 0;h < 4;h++) {
            int x = i + dx[h];
            int y = j + dy[h];
            if (0 <= x && x < n && 0 <= y && y < m && !vis[x][y] && board[x][y] == word[pos + 1])
                if (dfs(board, word, x, y, pos + 1))return true;
        }
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<string>& board, string word) {
        n = board.size(), m = board[0].size();
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (board[i][j] == word[0])if (dfs(board, word, i, j, 0)) return true;
        return false;
    }
};
int main()
{
    Solution s;
    vector<string> v{ "XEDD","EEZS","DDXX" };
    s.exist(v, "XEEE");
	return 0;
}