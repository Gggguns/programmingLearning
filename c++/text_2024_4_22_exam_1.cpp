#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    str = ' ' + str;
    int sz = str.size();
    vector<int> dp(sz);
    string Res;
    int Max = 0;
    for (int i = 1;i < sz;i++) {
        if (str[i] <= '9' && str[i] >= '0')dp[i] = dp[i - 1] + 1;
        if (Max < dp[i]) {
            Max = dp[i];
            Res = str.substr(i - Max + 1, Max);
        }
    }
    cout << Res;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")