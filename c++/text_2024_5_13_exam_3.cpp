#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<long long> nums(n);
    long long Sum = 0;
    for (int i = 0;i < n;i++) {
        cin >> nums[i];
        Sum += nums[i];
    }
    if (Sum % 2 != 0)cout << "false";
    else {
        Sum /= 2;
        vector<bool> dp(Sum + 1);
        for (auto e : nums) {
            dp[e] = true;
            for (int i = e + 1;i <= Sum;i++)dp[i] = dp[i - e];
            if (dp[Sum])break;
        }
        if (dp[Sum])cout << "true";
        else cout << "false";
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")