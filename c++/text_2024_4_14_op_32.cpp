#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vv(n + 1, vector<int>(m + 1));
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                vv[i][j] = vv[i - 1][j] + vv[i][j - 1] - vv[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int hrow = 0, hcol = 0, lrow = 0, lcol = 0;
        vector<vector<int>> answer(n, vector<int>(m));
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                if (i >= i - k && i <= i + k && j >= j - k && j <= j + k) {
                    hrow = min(i + k, n);
                    hcol = min(j + k, m);
                    lrow = max(i - k, 1);
                    lcol = max(j - k, 1);
                    answer[i - 1][j - 1] = vv[hrow][hcol] + vv[lrow - 1][lcol - 1] - vv[hrow][lcol - 1] - vv[lrow - 1][hcol];
                }
            }
        }
        return answer;
    }
};
int main()
{
	return 0;
}