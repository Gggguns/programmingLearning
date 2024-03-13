#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int Begin = 0, End = 0;
    int MaxDay = 81;
    vector<long long> dp(MaxDay);
    dp[0] = 0;dp[1] = 1;
    for (int i = 2;i < dp.size();i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    while (cin >> Begin >> End) { // 注意 while 处理多个 case
        long long Sum = 0;
        for (int i = Begin;i < End + 1;i++)
        {
            Sum += dp[i];
        }
        cout << Sum << endl;
    }
}
// 64 位输出请用 printf("%lld")