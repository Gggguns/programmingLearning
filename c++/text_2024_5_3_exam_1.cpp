#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
using namespace std;

int main() {
    long long num = 0, Res = 0, R = 0;
    cin >> num;
    vector<long long> v;
    while (num) {
        R = num % 10;
        num /= 10;
        if (R % 2 == 0)v.push_back(0);
        else v.push_back(1);
    }
    long long i = v.size() - 1;
    for (;i >= 0;i--) {
        Res = Res * 10 + v[i];
    }
    cout << Res;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")