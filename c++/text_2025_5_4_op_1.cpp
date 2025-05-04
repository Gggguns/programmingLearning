#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<long long>> precvsum(n + 1, vector<long long>(m + 1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                precvsum[i + 1][j + 1] = mat[i][j] + precvsum[i][j + 1] + precvsum[i + 1][j] - precvsum[i][j];
            }
        }
        vector<vector<int>> answer(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int a = max(0, i - k) + 1;
                int b = max(0, j - k) + 1;
                int c = min(i + k, n - 1) + 1;
                int d = min(j + k, m - 1) + 1;
                answer[i][j] = precvsum[c][d] - precvsum[c][b - 1] - precvsum[a - 1][d] + precvsum[a - 1][b - 1];
            }
        }
        return answer;
    }
};
int main()
{
    return 0;
}