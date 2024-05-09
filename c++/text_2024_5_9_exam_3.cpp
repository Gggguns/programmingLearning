#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int V = 0, n = 0;
    cin >> V >> n;
    vector<int> volumes(n);
    //记录n个物品的体积
    for (int i = 0;i < n;i++)cin >> volumes[i];
    //确定使用体积的最大值
    vector<vector<int>> dp(n, vector<int>(V + 1));
    //初始化
    for (int i = volumes[0];i <= V;i++)dp[0][i] = volumes[0];
    //填表
    for (int i = 1;i < n;i++) {
        //当前物品的体积
        int cur = volumes[i];
        for (int j = 0;j <= V;j++) {
            if (j - cur >= 0)dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cur] + cur);
            else dp[i][j] = dp[i - 1][j];
        }
    }
    //计算剩余体积的最小值
    int Res = V - dp[n - 1][V];
    cout << Res;
    return 0;
}