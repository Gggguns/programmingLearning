#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    long long n = 0, k = 0, num = 0;
    cin >> n >> k;
    vector<long long> a(n + 1), b(n + 1);
    for (long long i = 1;i <= n;i++) {
        cin >> num;
        a[i] = a[i - 1] + num;
    }
    for (long long i = 1;i <= n;i++) {
        cin >> num;
        b[i] = b[i - 1] + num;
    }
    long long dayi = 0, happyVal = 0, shameVal = 0;
    long long tempi = 0, temph = 0, temps = 0;
    for (tempi = 1;tempi <= n;tempi++) {
        long long begin = tempi - 1;
        long long end = (begin + k) > n ? n : (begin + k);
        temph = a[end] - a[begin];
        temps = b[end] - b[begin];
        if (temph > happyVal || (temph == happyVal && temps < shameVal)) {
            dayi = tempi;
            happyVal = temph;
            shameVal = temps;
        }
    }
    cout << dayi;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")