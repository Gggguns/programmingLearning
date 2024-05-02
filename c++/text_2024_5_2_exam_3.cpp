#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    string str;
    cin >> str;
    str = ' ' + str;
    int num = 0;
    cin >> num;
    int n = str.size();
    double Max = 0;
    string Res;
    vector<vector<double>> dp(n, vector<double>(n));
    for (int i = n - 1;i >= 1;i--) {
        for (int j = i;j < n;j++) {
            if (i + 1 < j)dp[i][j] = dp[i + 1][j - 1];
            if (str[i] == 'C' || str[i] == 'G')dp[i][j]++;
            if (i != j && (str[j] == 'C' || str[j] == 'G'))dp[i][j]++;
            int len = j - i + 1;
            double rate = dp[i][j] / len;
            if (len == num && rate >= Max) {
                Max = rate;
                Res = str.substr(i, len);
            }
        }
    }
    cout << Res;
    return 0;
}