#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cmath>
#include<unordered_map>
using namespace std;
bool Prime(long long num) {
    if (num == 0 || num == 1)return false;
    if (num == 2)return true;
    long long n = sqrt(num);
    for (long long i = 2;i <= n;i++) {
        if (num % i == 0)return false;
    }
    return true;
}
int main() {
    string str;
    cin >> str;
    long long Max = -0x3fffffff, Min = 0x3fffffff;
    unordered_map<char, long long> hash;
    for (auto e : str) {
        hash[e]++;
    }
    for (auto e : hash) {
        if (e.second > Max)Max = e.second;
        if (e.second < Min)Min = e.second;
    }
    long long Res = Max - Min;
    if (Prime(Res))cout << "Lucky Word\n" << Res;
    else cout << "No Answer\n" << 0;
    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")