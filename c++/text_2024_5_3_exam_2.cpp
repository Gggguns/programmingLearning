#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main() {
    long long n = 0, m = 0;
    scanf("%lld %lld", &n, &m);
    vector<long long> Col(n);
    vector<long long> Row(m);
    vector<vector<long long>> nums(n, vector<long long>(m));
    for (long long i = 0;i < n;i++) {
        for (long long j = 0;j < m;j++) {
            scanf("%lld", &nums[i][j]);
            Col[i] += nums[i][j];
            Row[j] += nums[i][j];
        }
    }
    for (long long i = 0;i < n;i++) {
        for (long long j = 0;j < m;j++) {
            printf("%lld ", Col[i] + Row[j] - nums[i][j]);
        }
        cout << endl;
    }
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")